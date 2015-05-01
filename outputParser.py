import sys, os
sys.path.append(os.path.join(os.path.dirname(__file__), "../", "DCEC_Library"))
import cleaning
import string
from DCECContainer import DCECContainer

def nextQuant(prev):
	this = string.ascii_lowercase
	prevquant = prev[0]
	prevmult = int(prev[1:])
	if prevquant == 'z':
		newquant = 'a'
		newmult = prevmult+1
	else:
		newquant = this[this.find(prevquant)+1]
		newmult = prevmult
	return newquant+str(newmult)

def overwriteQuant(quants,binding,sort,quantMap):
	for thing in enumerate(quants):
		if thing[1] == quantMap[binding]:
			quants[thing[0]-1] =  sort

def storeQuant(quants,binding,sort,transformDict,quantMap):
	if not "TEMP" in quantMap.keys():
		quantMap["TEMP"] = 'a0'
	quantifier = nextQuant(quantMap["TEMP"])
	while(quantifier in transformDict.keys()):
		quantifier = nextQuant(quantifier)
	quantMap[binding] = quantifier
	quantMap[quantifier] = binding
	quants.append(sort)
	quants.append(quantMap[binding])
	quantMap["TEMP"] = quantifier
	

def funcSorts(statement,sorts):
	indexList = {}	
	for sort in sorts:
		temp = statement.find(sort)
		if not temp == -1:
			indexList[temp] = sort
	returnList = []
	for arg in sorted(indexList.keys()):
		returnList.append(indexList[arg])
	return returnList

def cleanArg(arg,sorts):
	newArg = arg
	for sort in sorts:
		newArg = newArg.replace(sort,"")
	if newArg == arg:
		return arg
	else:
		return newArg[:-1]

def findSubTokens(statement,transformDict,sorts,quants,quantMap):
	#Find the sub-level tokens at this level of parsing
	temp = statement[1:-1].strip(",")	
	level = 0
	highlevel = ""
	sublevel = []
	for index in range(0,len(temp)):
		if temp[index] == "(":
			level += 1
			if(level == 1):
				sublevel.append([index,cleaning.getMatchingCloseParen(temp,index)+1])
			continue
		if temp[index] == ')':
			level -= 1
			continue
		if level == 0:
			highlevel = highlevel + temp[index]
	#These are the function components. One is the function name, the others are its args.   	
	args = highlevel.split(",")
	#Find quantifiers
	#If there is a singular thing
	if args[0] in sorts:
		if not args[1] == "":
			if not args[1] in quantMap.keys() and not args[1] in transformDict.keys():
				storeQuant(quants,args[1],args[0],transformDict,quantMap)
			elif not args[1] in transformDict.keys():
				overwriteQuant(quants,args[1],args[0],quantMap)
	#If there is a funciton
	else:
		argSorts = funcSorts(args[0],sorts)
		for sort in range(0,len(argSorts)-1):
			if not args[1+sort] == "":
				if not args[1+sort] in quantMap.keys() and not args[1] in transformDict.keys():
					storeQuant(quants,args[1+sort],"Boolean",transformDict,quantMap)
	place = 0
	#Recurse
	for index in range(0,len(args)):
		if args[index] == "":
			args[index] = findSubTokens(temp[sublevel[place][0]:sublevel[place][1]],transformDict,sorts,quants,quantMap)
			place += 1
	return args

def makeFuncs(quants,statementlist,sorts,transformDict,quantMap):
	#Return atomics
	if isinstance(statementlist,str):
		returnlist = []
		if statementlist in transformDict.keys():
			returnlist.append(transformDict[statementlist][0])
		elif not statementlist in quantMap.keys():
			storeQuant(quants,statementlist,"Boolean",transformDict,quantMap)
			returnlist.append(quantMap[statementlist])
		else:
			returnlist.append(quantMap[statementlist])
		return returnlist	
	#If there is a sort, strip it
	if statementlist[0] in sorts:
		return makeFuncs(quants,statementlist[1],sorts,transformDict,quantMap)
	#Otherwise there is a function to strip
	newlist = []
	for arg in enumerate(statementlist):
		if isinstance(arg[1],list):
			newlist.append(makeFuncs(quants,statementlist[arg[0]],sorts,transformDict,quantMap))
		else:
			newlist.append(arg[1])
	#Clean the arguments so that they are of the right form
	for arg in enumerate(newlist):
		if isinstance(arg[1],list):
			pass
		elif arg[1] in transformDict.keys():
			newlist[arg[0]] = transformDict[arg[1]][0]
		elif arg[1] in quantMap.keys():
			newlist[arg[0]] = quantMap[arg[1]]
		else:
			storeQuant(quants,arg[1],"Boolean",transformDict,quantMap)
			newlist[arg[0]] = quantMap[arg[1]]
	#return the cleaned list
	return newlist

def tokenizeSPASS(partialStatement,sorts,transformDict,quantMap):
	#If there are no constraints	
	if(partialStatement == ""):
		return [],[]
	#Strip all the unneccesary information
	statements = partialStatement.strip(" ").strip("->").strip(" ").split(" ")
	for statement in enumerate(statements):
		if(statement[1] == "->"):
			statements[statement[0]] = "TEMP"
			continue
		temp = statement[1]
		while True:
			nextTemp = temp.strip(".").strip(" ").strip("*").strip("+")
			if(temp ==nextTemp):
				statements[statement[0]] = nextTemp
				break
			else:
				temp = nextTemp
	#Conclusions are weird, stupid SPASS
	if statements[-1] == "":
		statements = statements[:-2]
	#Initialize the return lists
	quants = []
	funcs = []
	#Find all the neccesary information
	for statement in statements:
		#Implies is weird
		if(statement == "TEMP"):
			funcs.append(["TEMP"])
			continue
		#Find the functions derived in the proof
		temp = cleaning.tuckFunctions(statement)
		tokens = findSubTokens(temp,transformDict,sorts,quants,quantMap)
		#Funcs have isValid in front
		if tokens[0] == "isValid":
			funcs.append(makeFuncs(quants,tokens[1],sorts,transformDict,quantMap))
	#Implies is weird, collapse all the implies
	returner = []
	index = len(funcs)-1
	while index >= 0:
		if funcs[index-1][0] == "TEMP":
			returner.append(["implies",funcs[index-2],funcs[index]])
			index -= 3
		else:
			returner.append(funcs[index])
			index -= 1
	funcs = returner
	return quants,funcs
	
def tokenToString(token):
	returnString = ""
	for arg in token:
		if isinstance(arg,list):
			if len(arg) > 1:
				returnString += tokenToString(arg)+" "
			else:
				returnString += arg[0]+" "
		else:
			returnString += arg+" "
	returnString = returnString.strip(" ")
	if(len(token) > 1):
		returnString = "("+returnString+")"
	return returnString
	
def tokensToString(quants,constraints,results):
	returnString = ""
	numEndParens = 0
	#If there is nothing, just return nothing
	if len(constraints) == 0 and len(results) == 0:
		return returnString	
	#Translate to DCEC-quantifiers
	for quant in range(0,len(quants)/2):
		returnString += "(forAll ("
		numEndParens += 1			
		returnString += quants[quant*2]+" "
		returnString += quants[quant*2+1]+") "
	#Translate to DCEC-constraints
	place = 0	
	constraintString = ""
	if len(constraints) == 0:
		pass
	else:
		while place < len(constraints)-1:
			constraintString += "(and "
			adder = tokenToString(constraints[place])
			constraintString += adder+" "
			place += 1
		adder = tokenToString(constraints[-1])
		constraintString += adder
		for x in range(0,place):
			constraintString += ")"
	#Translate to DCEC-results
	place = 0	
	resultString = ""
	if len(results) == 0:
		return resultString
	else:
		while place < len(results)-1:
			resultString += "(and "
			adder = tokenToString(results[place])
			resultString += adder+","
			place += 1
		adder = tokenToString(results[-1])
		resultString += adder
		for x in range(0,place):
			resultString += ")"
	#Make the implication
	if constraintString == "":
		returnString += resultString
	else:
		returnString += "(implies "+constraintString+" "+resultString+")"
	#Add end parens
	for whatevs in range(0,numEndParens):
		returnString += ")"
	#Return the completed DCEC statement
	return returnString

		
def toSNotation(SPASSstatement,sorts,transformDict):
	#The quantifiers and conclusion are seperated by ||
	templist = SPASSstatement.split("||")
	if not len(templist) == 2:
		return ""
	#Create lists of tokens
	quants = []
	quantMap = {}
	quants1,constraints = tokenizeSPASS(templist[0],sorts,transformDict,quantMap)
	quants2,results = tokenizeSPASS(templist[1],sorts,transformDict,quantMap)
	quants = quants1
	#add quantifiers in a setwise fashion
	for quant in range(0,len(quants2)/2):
		if not quants2[quant*2+1] in quants:
			quants = quants + quants2[quant*2:quant*2+2]
	#stringify the tokens
	returnString = tokensToString(quants,constraints,results)
	return returnString

def parseOutput(outputTree):
	outputContainer = DCECContainer()
	currentStatement = toSNotation(outputTree.conclusion)

if __name__ == "__main__":
	transformDict = {}
	transformDict["Test2BooleanAgent"] = ["Test"]
	transformDict["Test1Boolean"] = ["Test"]
	transformDict["a0"] = ["a"]
	transformDict["James0"] = ["james"]
	outputContainer = DCECContainer()
	outputContainer.namespace.addCodeSort("Boolean")
	outputContainer.namespace.addCodeSort("Agent")
	print toSNotation("Boolean(U) Boolean(Test2BooleanAgent(Boolean(Test1Boolean(a0)),skc0)) isValid(Test2BooleanAgent(Boolean(Test1Boolean(a0)),skc0)) Agent(skc0) isValid(U) || -> isValid(U)* -> isValid(skc0)*.",outputContainer.namespace.sorts,transformDict)
	print toSNotation("|| -> isValid(Agent(James0))*.",outputContainer.namespace.sorts,transformDict)
	print toSNotation("Boolean(U) isValid(V) || isValid(Test1Boolean(U)) -> isValid(U)",outputContainer.namespace.sorts,transformDict)
	print toSNotation("Boolean(V) isValid(U) Boolean(U) || isValid(Test1Boolean(V)) -> isValid(V)",outputContainer.namespace.sorts,transformDict)
