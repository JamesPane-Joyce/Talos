import subprocess
from sets import Set
import sys, os
from proofTree import proofTree
from outputParser import toSNotation
sys.path.append(os.path.join(os.path.dirname(__file__), '../', 'DCEC_Library'))
from DCEC_Library.DCECContainer import DCECContainer


class spassContainer():
    directory = os.path.dirname(__file__)
    DCECVersion = ""
    input = ""
    errors = ""
    output = ""
    result = None
    axioms = dict([])
    discoveries = []
    sorts = []
    conjecture = None
    proof=None

    simultaneousRules = dict([
        ("CONJUNCTION_INTRODUCTION",("formula(forall([Boolean(z),Boolean(y)],implies(and(isValid(z),isValid(y)),isValid(And2BooleanBoolean(z,y)))),CONJUNCTION_INTRODUCTION).",["And2BooleanBoolean"])),
        ("DCEC_RULE_1",("formula(forall([Moment(z),Agent(y),Boolean(x)],isValid(C2MomentBoolean(z,Implies2BooleanBoolean(P3AgentMomentBoolean(y,z,x),K3AgentMomentBoolean(y,z,x))))),DCEC_RULE_1).",["C2MomentBoolean","Implies2BooleanBoolean","P3AgentMomentBoolean","K3AgentMomentBoolean"])),
        ("DCEC_RULE_10",("formula(forall([Moment(z),Boolean(y),Boolean(x),Boolean(w)],isValid(C2MomentBoolean(z,Implies2BooleanBoolean(Implies2BooleanBoolean(And2BooleanBoolean(y,x),w),Implies2BooleanBoolean(y,Implies2BooleanBoolean(x,w)))))),DCEC_RULE_10).",["C2MomentBoolean","Implies2BooleanBoolean","And2BooleanBoolean"])),
        ("DCEC_RULE_11A",("formula(forall([Agent(z),Moment(y),Boolean(x),Boolean(w)],implies(and(isValid(B3AgentMomentBoolean(z,y,Implies2BooleanBoolean(x,w))),isValid(B3AgentMomentBoolean(z,y,x))),isValid(B3AgentMomentBoolean(z,y,w)))),DCEC_RULE_11A).",["B3AgentMomentBoolean","Implies2BooleanBoolean"])),
        ("DCEC_RULE_11B",("formula(forall([Agent(z),Moment(y),Boolean(x),Boolean(w)],implies(and(isValid(B3AgentMomentBoolean(z,y,x)),isValid(B3AgentMomentBoolean(z,y,w))),isValid(B3AgentMomentBoolean(z,y,And2BooleanBoolean(x,w))))),DCEC_RULE_11B).",["B3AgentMomentBoolean","And2BooleanBoolean"])),
        ("DCEC_RULE_12",("formula(forall([Agent(z),Agent(x),Moment(y),Boolean(w)],implies(isValid(S4AgentAgentMomentBoolean(z,x,y,w)),isValid(B3AgentMomentBoolean(x,y,B3AgentMomentBoolean(z,y,w))))),DCEC_RULE_12).",["S4AgentAgentMomentBoolean","B3AgentMomentBoolean"])),
        ("DCEC_RULE_13",("formula(forall([Agent(z),Moment(y),ActionType(x)],implies(isValid(I3AgentMomentBoolean(z,y,Happens2EventMoment(Action2AgentActionType(Self1Agent(z),x),y))),isValid(P3AgentMomentBoolean(z,y,Happens2EventMoment(Action2AgentActionType(Self1Agent(z),x),y))))),DCEC_RULE_13).",["I3AgentMomentBoolean","Happens2EventMoment","Action2AgentActionType","Self1Agent","P3AgentMomentBoolean"])),
        ("DCEC_RULE_14",("formula(forall([Agent(z),Moment(y),Boolean(x),ActionType(w)],implies(and(isValid(B3AgentMomentBoolean(z,y,x)),isValid(B3AgentMomentBoolean(z,y,O4AgentMomentBooleanBoolean(Self1Agent(z),y,x,Happens2EventMoment(Action2AgentActionType(Self1Agent(z),w),y)))),isValid(O4AgentMomentBooleanBoolean(z,y,x,Happens2EventMoment(Action2AgentActionType(Self1Agent(z),w),y)))),isValid(K3AgentMomentBoolean(z,y,I3AgentMomentBoolean(Self1Agent(z),y,Happens2EventMoment(Action2AgentActionType(Self1Agent(z),w),y)))))),DCEC_RULE_14).",["B3AgentMomentBoolean","O4AgentMomentBooleanBoolean","Happens2EventMoment","Action2AgentActionType","Self1Agent","K3AgentMomentBoolean","I3AgentMomentBoolean"])),
        ("DCEC_RULE_15",("formula(forall([Boolean(z),Boolean(y),Agent(x),Moment(w),Boolean(v)],implies(isValid(Iff2BooleanBoolean(z,y)),isValid(Iff2BooleanBoolean(O4AgentMomentBooleanBoolean(x,w,z,v),O4AgentMomentBooleanBoolean(x,w,y,v))))),DCEC_RULE_15).",["Iff2BooleanBoolean","O4AgentMomentBooleanBoolean"])),
        ("DCEC_RULE_2",("formula(forall([Moment(z),Agent(y),Boolean(x)],isValid(C2MomentBoolean(z,Implies2BooleanBoolean(K3AgentMomentBoolean(y,z,x),B3AgentMomentBoolean(y,z,x))))),DCEC_RULE_2).",["C2MomentBoolean","Implies2BooleanBoolean","B3AgentMomentBoolean"])),
        ("DCEC_RULE_3",("formula(forall([Moment(z),Boolean(y),Agent(x),Agent(w),Agent(v)],implies(isValid(C2MomentBoolean(z,y)),isValid(K3AgentMomentBoolean(x,z,K3AgentMomentBoolean(w,z,K3AgentMomentBoolean(v,z,y)))))),DCEC_RULE_3).",["C2MomentBoolean","K3AgentMomentBoolean"])),
        ("DCEC_RULE_4",("formula(forall([Agent(z),Moment(y),Boolean(x)],implies(isValid(K3AgentMomentBoolean(z,y,x)),isValid(x))),DCEC_RULE_4).",["K3AgentMomentBoolean"])),
        ("DCEC_RULE_5",("formula(forall([Moment(z),Agent(y),Boolean(x),Boolean(w)],isValid(C2MomentBoolean(z,Implies2BooleanBoolean(K3AgentMomentBoolean(y,z,Implies2BooleanBoolean(x,w)),Implies2BooleanBoolean(K3AgentMomentBoolean(y,z,x),K3AgentMomentBoolean(y,z,w)))))),DCEC_RULE_5).",["C2MomentBoolean","Implies2BooleanBoolean","K3AgentMomentBoolean"])),
        ("DCEC_RULE_6",("formula(forall([Moment(z),Agent(y),Boolean(x),Boolean(w)],isValid(C2MomentBoolean(z,Implies2BooleanBoolean(B3AgentMomentBoolean(y,z,Implies2BooleanBoolean(x,w)),Implies2BooleanBoolean(B3AgentMomentBoolean(y,z,x),B3AgentMomentBoolean(y,z,w)))))),DCEC_RULE_6).",["C2MomentBoolean","Implies2BooleanBoolean","B3AgentMomentBoolean"])),
        ("DCEC_RULE_7",("formula(forall([Moment(z),Boolean(y),Boolean(x)],isValid(C2MomentBoolean(z,Implies2BooleanBoolean(C2MomentBoolean(z,Implies2BooleanBoolean(y,x)),Implies2BooleanBoolean(C2MomentBoolean(z,y),C2MomentBoolean(z,x)))))),DCEC_RULE_7).",["C2MomentBoolean","Implies2BooleanBoolean"])),
        ("DCEC_RULE_9",("formula(forall([Moment(z),Boolean(y),Boolean(x)],isValid(C2MomentBoolean(z,Implies2BooleanBoolean(Iff2BooleanBoolean(y,x),Implies2BooleanBoolean(Not1Boolean(y),Not1Boolean(x)))))),DCEC_RULE_9).",["C2MomentBoolean","Implies2BooleanBoolean","Iff2BooleanBoolean","Not1Boolean"])),
        ("MODUS_PONENS",("formula(forall([Boolean(z),Boolean(y)],implies(and(isValid(z),isValid(Implies2BooleanBoolean(z,y))),isValid(y))),MODUS_PONENS).",["Implies2BooleanBoolean"])),
    ])
    temporalRules = dict([
        ("MODUS_PONENS",("formula(forall([Boolean(z),Boolean(y)],implies(and(isValid(z),isValid(Implies2BooleanBoolean(z,y))),isValid(y))),MODUS_PONENS).",["Implies2BooleanBoolean"])),
        ("CONJUNCTION_INTRODUCTION",("formula(forall([Boolean(z),Boolean(y)],implies(and(isValid(z),isValid(y)),isValid(And2BooleanBoolean(z,y)))),CONJUNCTION_INTRODUCTION).",["And2BooleanBoolean"])),
        ("DCEC_RULE_1",("formula(forall([Moment(z),Agent(y),Boolean(x)],isValid(C2MomentBoolean(z,Implies2BooleanBoolean(P3AgentMomentBoolean(y,z,x),K3AgentMomentBoolean(y,z,x))))),DCEC_RULE_1).",["C2MomentBoolean","Implies2BooleanBoolean","P3AgentMomentBoolean","K3AgentMomentBoolean"])),
        ("DCEC_RULE_2",("formula(forall([Moment(z),Agent(y),Boolean(x)],isValid(C2MomentBoolean(z,Implies2BooleanBoolean(K3AgentMomentBoolean(y,z,x),B3AgentMomentBoolean(y,z,x))))),DCEC_RULE_2).",["C2MomentBoolean","Implies2BooleanBoolean","K3AgentMomentBoolean","B3AgentMomentBoolean"])),
        ("DCEC_RULE_3",("formula(forall([Moment(z),Moment(y),Moment(x),Moment(w),Boolean(v),Agent(u),Agent(t),Agent(s)],implies(and(isValid(Lessorequal2MomentMoment(z,y)),isValid(Lessorequal2MomentMoment(y,x)),isValid(Lessorequal2MomentMoment(x,w)),isValid(C2MomentBoolean(z,v))),isValid(K3AgentMomentBoolean(u,y,K3AgentMomentBoolean(t,x,K3AgentMomentBoolean(s,w,v)))))),DCEC_RULE_3).",["Lessorequal2MomentMoment","C2MomentBoolean","K3AgentMomentBoolean"])),
        ("DCEC_RULE_4",("formula(forall([Agent(z),Moment(y),Boolean(x)],implies(isValid(K3AgentMomentBoolean(z,y,x)),isValid(x))),DCEC_RULE_4).",["K3AgentMomentBoolean"])),
        ("DCEC_RULE_5",("formula(forall([Moment(z),Agent(y),Boolean(x),Boolean(w),Moment(v),Moment(u),Moment(t)],implies(and(isValid(Lessorequal2MomentMoment(v,t)),isValid(Lessorequal2MomentMoment(u,t))),isValid(C2MomentBoolean(z,Implies2BooleanBoolean(K3AgentMomentBoolean(y,v,Implies2BooleanBoolean(x,w)),Implies2BooleanBoolean(K3AgentMomentBoolean(y,u,x),K3AgentMomentBoolean(y,t,w))))))),DCEC_RULE_5).",["Lessorequal2MomentMoment","C2MomentBoolean","Implies2BooleanBoolean","K3AgentMomentBoolean"])),
        ("DCEC_RULE_6",("formula(forall([Moment(z),Agent(y),Boolean(x),Boolean(w),Moment(v),Moment(u),Moment(t)],implies(and(isValid(Lessorequal2MomentMoment(v,t)),isValid(Lessorequal2MomentMoment(u,t))),isValid(C2MomentBoolean(z,Implies2BooleanBoolean(B3AgentMomentBoolean(y,v,Implies2BooleanBoolean(x,w)),Implies2BooleanBoolean(B3AgentMomentBoolean(y,u,x),B3AgentMomentBoolean(y,t,w))))))),DCEC_RULE_6).",["Lessorequal2MomentMoment","C2MomentBoolean","Implies2BooleanBoolean","B3AgentMomentBoolean"])),
        ("DCEC_RULE_7",("formula(forall([Moment(z),Boolean(y),Boolean(x),Moment(w),Moment(v),Moment(u)],implies(and(isValid(Lessorequal2MomentMoment(w,u)),isValid(Lessorequal2MomentMoment(v,u))),isValid(C2MomentBoolean(z,Implies2BooleanBoolean(C2MomentBoolean(w,Implies2BooleanBoolean(y,x)),Implies2BooleanBoolean(C2MomentBoolean(v,y),C2MomentBoolean(u,x))))))),DCEC_RULE_7).",["Lessorequal2MomentMoment","C2MomentBoolean","Implies2BooleanBoolean"])),
        ("DCEC_RULE_9",("formula(forall([Moment(z),Boolean(y),Boolean(x)],isValid(C2MomentBoolean(z,Implies2BooleanBoolean(Iff2BooleanBoolean(y,x),Implies2BooleanBoolean(Not1Boolean(y),Not1Boolean(x)))))),DCEC_RULE_9).",["C2MomentBoolean","Implies2BooleanBoolean","Iff2BooleanBoolean","Not1Boolean"])),
        ("DCEC_RULE_10",("formula(forall([Moment(z),Boolean(y),Boolean(x),Boolean(w)],isValid(C2MomentBoolean(z,Implies2BooleanBoolean(Implies2BooleanBoolean(And2BooleanBoolean(y,x),w),Implies2BooleanBoolean(y,Implies2BooleanBoolean(x,w)))))),DCEC_RULE_10).",["C2MomentBoolean","Implies2BooleanBoolean","And2BooleanBoolean"])),
        ("DCEC_RULE_11A",("formula(forall([Agent(z),Moment(y),Boolean(x),Boolean(w)],implies(and(isValid(B3AgentMomentBoolean(z,y,Implies2BooleanBoolean(x,w))),isValid(B3AgentMomentBoolean(z,y,x))),isValid(B3AgentMomentBoolean(z,y,w)))),DCEC_RULE_11A).",["B3AgentMomentBoolean","Implies2BooleanBoolean"])),
        ("DCEC_RULE_11B",("formula(forall([Agent(z),Moment(y),Boolean(x),Boolean(w)],implies(and(isValid(B3AgentMomentBoolean(z,y,x)),isValid(B3AgentMomentBoolean(z,y,w))),isValid(B3AgentMomentBoolean(z,y,And2BooleanBoolean(x,w))))),DCEC_RULE_11B).",["B3AgentMomentBoolean","And2BooleanBoolean"])),
        ("DCEC_RULE_12",("formula(forall([Agent(z),Agent(x),Moment(y),Boolean(w)],implies(isValid(S4AgentAgentMomentBoolean(z,x,y,w)),isValid(B3AgentMomentBoolean(x,y,B3AgentMomentBoolean(z,y,w))))),DCEC_RULE_12).",["S4AgentAgentMomentBoolean","B3AgentMomentBoolean"])),
        ("DCEC_RULE_13",("formula(forall([Agent(z),Moment(y),ActionType(x),Moment(w)],implies(isValid(I3AgentMomentBoolean(z,y,Happens2EventMoment(Action2AgentActionType(Self1Agent(z),x),w))),isValid(P3AgentMomentBoolean(z,y,Happens2EventMoment(Action2AgentActionType(Self1Agent(z),x),w))))),DCEC_RULE_13).",["I3AgentMomentBoolean","Happens2EventMoment","Action2AgentActionType","Self1Agent","P3AgentMomentBoolean"])),
        ("DCEC_RULE_14",("formula(forall([Agent(z),Moment(y),Boolean(x),ActionType(w),Moment(v)],implies(and(isValid(Lessorequal2MomentMoment(y,v)),isValid(B3AgentMomentBoolean(z,y,x)),isValid(B3AgentMomentBoolean(z,y,O4AgentMomentBooleanBoolean(Self1Agent(z),y,x,Happens2EventMoment(Action2AgentActionType(Self1Agent(z),w),v)))),isValid(O4AgentMomentBooleanBoolean(z,y,x,Happens2EventMoment(Action2AgentActionType(Self1Agent(z),w),v)))),isValid(K3AgentMomentBoolean(z,y,I3AgentMomentBoolean(Self1Agent(z),y,Happens2EventMoment(Action2AgentActionType(Self1Agent(z),w),v)))))),DCEC_RULE_14).",["Lessorequal2MomentMoment","B3AgentMomentBoolean","O4AgentMomentBooleanBoolean","Self1Agent","Happens2EventMoment","Action2AgentActionType","I3AgentMomentBoolean"])),
        ("DCEC_RULE_15",("formula(forall([Boolean(z),Boolean(y),Agent(x),Agent(w),Boolean(v)],implies(isValid(Iff2BooleanBoolean(z,y)),isValid(Iff2BooleanBoolean(O4AgentMomentBooleanBoolean(x,w,z,v),O4AgentMomentBooleanBoolean(x,w,y,v))))),DCEC_RULE_15).",["Iff2BooleanBoolean","O4AgentMomentBooleanBoolean"]))
    ])

    symbolReverter = dict()

    #This constructor creates one of these containers and runs a proof with it
    #axiomContainer is a dcecContainer containing all the statements that will serve as axioms
    #query is a valid string within that container or a token tree from that container
    #justify indicates whether the prover should print a justification of the proof
    #timeout is the number of seconds the proof should run for before quitting
    #options is a string of SPASS options for the prover
    #simultaneous indicates whether a modified series of DCEC Inference rules that take place only in one time are used
    #discover indicates whether new statements that are discovered should be printed
    def __init__(self, axiomContainer, query, justify=False, timeout=-1, options="-Auto", simultaneous=False, discover=False, rules=["MODUS_PONENS","CONJUNCTION_INTRODUCTION","DCEC_RULE_1","DCEC_RULE_2","DCEC_RULE_3","DCEC_RULE_4","DCEC_RULE_5","DCEC_RULE_6","DCEC_RULE_7","DCEC_RULE_9","DCEC_RULE_10","DCEC_RULE_11A","DCEC_RULE_11B","DCEC_RULE_12","DCEC_RULE_13","DCEC_RULE_14","DCEC_RULE_15"]):
        self.sorts=axiomContainer.namespace.sorts
        self.addInferenceRules(simultaneous,rules)
        parsedStatements = self.parseStatements(axiomContainer)
        parsedQuery = self.parseStatement(axiomContainer,query,"CONJECTURE")
        self.conjecture = query
        self.addFunctions()
        self.addSorts(axiomContainer)
        self.addFormulas(simultaneous,rules,parsedStatements)
        self.addQuery(parsedQuery)
        self.spassExecute(axiomContainer,justify, timeout, options, discover,simultaneous)
    def addInferenceRules(self, simultaneous, rules):
        necessaryFuncDefs =dict([
            ("Action2AgentActionType",("action",2,"Action",["Agent","ActionType"])),
            ("Happens2EventMoment",("happens",2,"Boolean",["Event","Moment","Boolean"])),
            ("Self1Agent",("self",1,"Self",["Agent"])),
            ("P3AgentMomentBoolean",("P",3,"Boolean",["Agent","Moment","Boolean"])),
            ("C2MomentBoolean",("C",2,"Boolean",["Moment","Boolean"])),
            ("B3AgentMomentBoolean",("B",3,"Boolean",["Agent","Moment","Boolean"])),
            ("K3AgentMomentBoolean",("K",3,"Boolean",["Agent","Moment","Boolean"])),
            ("S4AgentAgentMomentBoolean",("S",4,"Boolean",["Agent","Agent","Moment","Boolean"])),
            ("I3AgentMomentBoolean",("I",3,"Boolean",["Agent","Moment","Boolean"])),
            ("O4AgentMomentBooleanBoolean",("O",4,"Boolean",["Agent","Moment","Boolean","Boolean"])),
            ("Not1Boolean",("not",1,"Boolean",["Boolean"])),
            ("Implies2BooleanBoolean",("implies",2,"Boolean",["Boolean","Boolean"])),
            ("And2BooleanBoolean",("and",2,"Boolean",["Boolean","Boolean"])),
            ("Iff2BooleanBoolean",("iff",2,"Boolean",["Boolean","Boolean"])),
            ("Lessorequal2MomentMoment",("lessOrEqual",2,"Boolean",["Moment","Moment"])),
        ])
        if simultaneous:
            for r in rules:
                for t in self.simultaneousRules[r][1]:
                    self.symbolReverter[t]=necessaryFuncDefs[t]
        else:
            for r in rules:
                for t in self.temporalRules[r][1]:
                    self.symbolReverter[t]=necessaryFuncDefs[t]

    def addSorts(self,container):
        self.input+="].\npredicates[\n(isValid,1)\n].\nsorts["
        for sort in container.namespace.sorts.keys():
            self.input+=sort+","
        self.input=self.input[:-1]
        self.input +="\n].\nend_of_list.\n\nlist_of_declarations.\n"
        for sort in container.namespace.sorts:
            if container.namespace.sorts[sort]!=[]:
                for subsort in container.namespace.sorts[sort]:
                    self.input+="subsort("+sort+","+subsort+").\n"
        temp = ["Z", "Y", "X", "W", "V", "U", "T", "S", "R", "Q", "P", "O", "N", "M", "L", "K", "J", "I", "H", "G", "F","E", "D", "C", "B", "A"]
        for key in self.symbolReverter:
            if self.symbolReverter[key][1]>0:
                self.input+="forall(["
                for x in range(0,self.symbolReverter[key][1]):
                    self.input+=temp[x]+","
                self.input=self.input[:-1]+"],"
            self.input+=self.symbolReverter[key][2]+"("+key
            if self.symbolReverter[key][1]>0:
                self.input+="("
                for x in range(0,self.symbolReverter[key][1]):
                    self.input+=temp[x]+","
                self.input=self.input[:-1]+"))"
            self.input+=").\n"



    #This method takes in a string representing a variable or function and makes it a unique identifier
    #(This way I don't have to muck about with differentiating between overloaded stuff)
    #It can be converted backwards later
    def convertToTerm(self, inputStr,returnType,sorts):
        convertedStr = inputStr.title()+str(len(sorts))
        for sort in sorts:
            convertedStr+=sort
        self.symbolReverter.setdefault(convertedStr,(inputStr,len(sorts),returnType,sorts))
        return convertedStr

    #This method takes in a DCECContainer and parses all the statements inside
    #It returns a list of fully parsed statements
    def parseStatements(self, axiomContainer):
        parsedStatements=[]
        axiomNum=1
        for statement in axiomContainer.statements:
            parsed=self.parseStatement(axiomContainer,statement,"AXIOM_"+str(axiomNum))
            self.axioms.setdefault("AXIOM_"+str(axiomNum),(axiomContainer,statement))
            parsedStatements.append(parsed)
            axiomNum+=1
        return parsedStatements

    #This method takes in a DCECContainer, a statement, a name for this axiom, and any quantified variables
    def parseStatement(self, container, statement, name, vars=[]):
        if statement is None:
            return ""
        tmp=False
        if isinstance(statement,str):
            newContainer = container.tokenize(statement)
            if newContainer == False:
                raise ValueError("The query is invalid within that set of axioms.")
            return self.parseStatement(newContainer,newContainer.statements[0],name,vars)
        parsed = ""
        if statement.funcName == "forAll" or statement.funcName == "exists":
            parsed += statement.funcName.lower() + "(["+container.sortOf(statement.args[0])+"("+statement.args[0] + ")]," + self.parseStatement(container,statement.args[1], "", vars + [statement.args[0]]) + ")"
        elif len(statement.args) == 0:
            parsed += "isValid(" + self.convertToTerm(statement.funcName,container.sortOf(statement),[]) + ")"
        else:
            parsed += "isValid(" + self.convertToTerm(statement.funcName, container.sortOf(statement),container.sortsOfParams(statement))+ "("
            parsed += self.parseSubStatements(container,statement.args, vars) + ")"
            parsed = ")".join(parsed.split(",)"))
        if name != "":
            parsed += ")," + name
        return parsed

    def parseSubStatements(self, container, substmts, vars=[]):
        parsed = ""
        for substmt in substmts:
            if not isinstance(substmt,str):
                parsed += self.convertToTerm(substmt.funcName,container.sortOf(substmt),container.sortsOfParams(substmt)) + "("
                parsed += self.parseSubStatements(container,substmt.args, vars) + "),"
            else:
                if not substmt in vars:
                    parsed += self.convertToTerm(substmt,container.sortOf(substmt),[]) + ","
                else:
                    parsed += substmt + ","
        return parsed

    def spassExecute(self, container, justify=False, timelimit=-1, options="-Auto", discover=False,simultaneous=False):
        findProof=True
        if discover or justify:
            for statement in container.statements:
                if statement.createSExpression().find("exists")!=-1:
                    print "DUE TO A QUIRK OF SPASS OUTPUT PROOFS AND GENERATED STATEMENTS CANNOT BE DERIVED FROM STATEMENTS WITH exists"
                    findProof=False
                    discover=False
                    break
        self.errors = ""
        self.output = ""
        self.rulesresult = None
        self.rules = []
        command = [self.directory + "/SPASS-3.7/SPASS/SPASS", "-TimeLimit=" + str(timelimit), "-Stdin"]
        command += options.split(" ")
        if justify:
            command.append("-DocProof")
        self.spass = subprocess.Popen(command, stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        self.output, self.errors = self.spass.communicate(self.input)
        self.parseProof(justify, findProof, discover, container,simultaneous)

    def addFunctions(self):
        self.input +="begin_problem(Test).\nlist_of_descriptions.\nname({*A DCEC Problem*}).\nauthor({*James Pane-Joyce*}).\nstatus(unsatisfiable).\ndescription({*This is a SPASS proof generated off of DCEC statements.*}).\nend_of_list.\n\nlist_of_symbols.\nfunctions[\n"

        for key in self.symbolReverter:
            self.input += "(" + key + "," + str(self.symbolReverter[key][1]) + "),\n"
        self.input = self.input[:-2] + "\n"

    def addQuery(self, query):
        self.input += "\nend_of_list.\n\nlist_of_formulae(conjectures).\n"
        self.input += "formula(" + query + ").\n"
        self.input += "end_of_list.\n\nend_problem.\n"

    def addFormulas(self, simultaneous, rules, formulas):
        self.input += "end_of_list.\n\nlist_of_formulae(axioms).\nformula(forall([x],implies(isValid(x),Boolean(x))),SORTING_RULE).\n"
        for r in rules:
            if simultaneous:
                self.input += self.simultaneousRules[r][0]+"\n"
            else:
                self.input += self.temporalRules[r][0]+"\n"
        for formula in formulas:
            self.input += "formula(" + formula + ").\n"

    def parseProof(self, justified, findProof, discover, container,simultaneous):
        index = self.output.find("SPASS beiseite: ")
        resultStr = self.output[index:self.output.find("\n", index)]
        if self.errors != "":
            self.result = ("Error Found", [], [])
        elif resultStr.find("Ran out of time.") != -1:
            self.result = ("Time Up", [], [])
        elif resultStr.find("Completion found.") != -1:
            self.result = ("Completion Found", [], [])
        elif resultStr.find("Proof found.") != -1:
            self.result = ("Proof Found", [], [])
            if justified:
                index = self.output.find("Here is a proof with ")
                proofStr = self.output[self.output.find("\n", index):self.output.find("\nFormulae used in the proof",index)]
                if findProof:
                    emptyContainer=DCECContainer()
                    emptyContainer.namespace=container.namespace
                    self.proof=proofTree(proofStr,emptyContainer,simultaneous,self.symbolReverter)
                index = self.output.find("Formulae used in the proof : ") + len("Formulae used in the proof : ")
                proofStr = self.output[index:self.output.find("\n", index)]
                steps = proofStr.split(" ")
                for x in range(len(steps)-1,-1,-1):
                    if steps[x]=="CONJECTURE":
                        steps.pop(x)
                    elif steps[x]=="SORTING_RULE":
                        steps.pop(x)
                    elif steps[x].startswith("declaration"):
                        steps.pop(x)
                steps=Set(steps)
                for step in steps:
                    if step in self.axioms:
                        self.result[1].append(self.axioms[step])
                    else:
                        self.result[2].append(step)
        logic = self.output[self.output.find("Given clause:"):self.output.find("SPASS V 3.7")]
        logic = logic.split("\n")
        self.discoveries=DCECContainer()
        self.discoveries.namespace=container.namespace
        if discover:
            index = len(logic) - 1
            while index >= 0:
                if logic[index][-4:]=="-> .":
                    logic.pop(index)
                else:
                    logic[index]=logic[index][logic[index].find("]")+1:]
                    tmperarotya= toSNotation(logic[index],container.namespace.sorts,self.symbolReverter)
                    if tmperarotya!="":
                        self.discoveries.addStatement(tmperarotya)
                index-=1


    def getResult(self):
        return self.result

    def resultToString(self):
        output = self.result[0] + "\n"
        for statement in self.result[1]:
            output += "\t" + statement[0].printStatement(statement[1]) + "\n"
        for rule in self.result[2]:
            output += "\t\t" + rule + "\n"
        return output

    def discoveriesToString(self):
        output = ""
        for discovery in self.discoveries.statements:
            output += self.discoveries.printStatement(discovery)+"\n"
        return output

    def getOutput(self):
        return self.output

    def getErrors(self):
        return self.errors

    def getAxioms(self):
        return self.axioms

    def getConjecture(self):
        return self.conjecture

    def getRules(self):
        return self.rules

    def proofToString(self):
        output=""
        for line in self.proof.proofTree.keys():
            output += line+"\n"
            for p in self.proof.proofTree[line]:
                output += "\t"+p+"\n"
        return output

    def proofToSlate(self):
        if self.proof==None:
            return self.proof
        counter=1
        numLookup=dict()
        emptySlate="(:DESCRIPTIONS(\n"
        for statement in self.proof.proofTree.keys():
            emptySlate+='\t(:X 0 :Y 0 :ID '+str(counter)+' :NAME "" :FORMULA "'
            emptySlate+=statement+'"'
            emptySlate+=" :JUSTIFICATION LOGIC::ASSUME)\n"
            numLookup[statement]=counter
            counter+=1
        emptySlate=emptySlate.replace('forAll','\\\\forall')
        for sort in self.sorts:
            emptySlate=emptySlate.replace(" "+sort+" ",' ')
        emptySlate+="\n) :STRUCTURES ("
        counter=1
        for statement in self.proof.proofTree.keys():
            premiseInts=[]
            for x in self.proof.proofTree[statement]:
                premiseInts.append(str(numLookup[x]))
            premiseInts="("+(" ".join(premiseInts))+")"
            if premiseInts=="()":
                premiseInts="NIL"
            emptySlate+="(:CONCLUSION "+str(counter)+" :PREMISES "+premiseInts+")"
            counter+=1
        emptySlate+=") :INTERFACE (:X 268 :Y 29 :WIDTH 1920 :HEIGHT 1037 :PROOF-SYSTEM LOGIC::FIRST-ORDER-LOGIC))"
        return emptySlate



















