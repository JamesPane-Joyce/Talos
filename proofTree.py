import sys, os
import copy
from outputParser import toSNotation

class proofTree():
    simultaneous=dict([
        ("isValid(U) isValid(V) ||  -> isValid(And2BooleanBoolean(V,U))*.","CONJUNCTION_INTRODUCTION"),
        ("Boolean(U) isValid(V) || isValid(Implies2BooleanBoolean(V,U))* -> isValid(U).","MODUS_PONENS"),
        ("Boolean(U) Moment(V) Agent(W) || isValid(K3AgentMomentBoolean(W,V,U))* -> isValid(U).","DCEC_RULE_4"),
        ("Boolean(U) Agent(V) Moment(W) ||  -> isValid(C2MomentBoolean(W,Implies2BooleanBoolean(K3AgentMomentBoolean(V,W,U),B3AgentMomentBoolean(V,W,U))))*.","DCEC_RULE_2"),
        ("Boolean(U) Agent(V) Moment(W) ||  -> isValid(C2MomentBoolean(W,Implies2BooleanBoolean(P3AgentMomentBoolean(V,W,U),K3AgentMomentBoolean(V,W,U))))*.","DCEC_RULE_1"),
        ("Boolean(U) Boolean(V) Moment(W) ||  -> isValid(C2MomentBoolean(W,Implies2BooleanBoolean(Iff2BooleanBoolean(V,U),Implies2BooleanBoolean(Not1Boolean(V),Not1Boolean(U)))))*.","DCEC_RULE_9"),
        ("Boolean(U) Boolean(V) Moment(W) ||  -> isValid(C2MomentBoolean(W,Implies2BooleanBoolean(C2MomentBoolean(W,Implies2BooleanBoolean(V,U)),Implies2BooleanBoolean(C2MomentBoolean(W,V),C2MomentBoolean(W,U)))))*.","DCEC_RULE_7"),
        ("Boolean(U) Boolean(V) Boolean(W) Moment(X) ||  -> isValid(C2MomentBoolean(X,Implies2BooleanBoolean(Implies2BooleanBoolean(And2BooleanBoolean(W,V),U),Implies2BooleanBoolean(W,Implies2BooleanBoolean(V,U)))))*.","DCEC_RULE_10"),
        ("Boolean(U) Moment(V) Agent(W) Agent(X) || isValid(S4AgentAgentMomentBoolean(X,W,V,U)) -> isValid(B3AgentMomentBoolean(W,V,B3AgentMomentBoolean(X,V,U)))*.","DCEC_RULE_12"),
        ("ActionType(U) Moment(V) Agent(W) || isValid(I3AgentMomentBoolean(W,V,Happens2EventMoment(Action2AgentActionType(Self1Agent(W),U),V))) -> isValid(P3AgentMomentBoolean(W,V,Happens2EventMoment(Action2AgentActionType(Self1Agent(W),U),V)))*.","DCEC_RULE_13"),
        ("Boolean(U) Boolean(V) Agent(W) Moment(X) ||  -> isValid(C2MomentBoolean(X,Implies2BooleanBoolean(B3AgentMomentBoolean(W,X,Implies2BooleanBoolean(V,U)),Implies2BooleanBoolean(B3AgentMomentBoolean(W,X,V),B3AgentMomentBoolean(W,X,U)))))*.","DCEC_RULE_6"),
        ("Boolean(U) Boolean(V) Agent(W) Moment(X) ||  -> isValid(C2MomentBoolean(X,Implies2BooleanBoolean(K3AgentMomentBoolean(W,X,Implies2BooleanBoolean(V,U)),Implies2BooleanBoolean(K3AgentMomentBoolean(W,X,V),K3AgentMomentBoolean(W,X,U)))))*.","DCEC_RULE_5"),
        ("Boolean(U) Boolean(V) Moment(W) Agent(X) || isValid(B3AgentMomentBoolean(X,W,V)) isValid(B3AgentMomentBoolean(X,W,U)) -> isValid(B3AgentMomentBoolean(X,W,And2BooleanBoolean(V,U)))*.","DCEC_RULE_11B"),
        ("Boolean(U) Boolean(V) Moment(W) Agent(X) || isValid(B3AgentMomentBoolean(X,W,V)) isValid(B3AgentMomentBoolean(X,W,Implies2BooleanBoolean(V,U)))* -> isValid(B3AgentMomentBoolean(X,W,U)).","DCEC_RULE_11A"),
        ("Agent(U) Agent(V) Agent(W) Boolean(X) Moment(Y) || isValid(C2MomentBoolean(Y,X)) -> isValid(K3AgentMomentBoolean(W,Y,K3AgentMomentBoolean(V,Y,K3AgentMomentBoolean(U,Y,X))))*.","DCEC_RULE_3"),
        ("Boolean(U) Agent(V) Agent(W) Boolean(X) Boolean(Y) || isValid(Iff2BooleanBoolean(Y,X)) -> isValid(Iff2BooleanBoolean(O4AgentMomentBooleanBoolean(W,V,Y,U),O4AgentMomentBooleanBoolean(W,V,X,U)))*.","DCEC_RULE_15"),
        ("ActionType(U) Boolean(V) Moment(W) Agent(X) || isValid(B3AgentMomentBoolean(X,W,V)) isValid(B3AgentMomentBoolean(X,W,O4AgentMomentBooleanBoolean(Self1Agent(X),W,V,Happens2EventMoment(Action2AgentActionType(Self1Agent(X),U),W))))* isValid(O4AgentMomentBooleanBoolean(X,W,V,Happens2EventMoment(Action2AgentActionType(Self1Agent(X),U),W))) -> isValid(K3AgentMomentBoolean(X,W,I3AgentMomentBoolean(Self1Agent(X),W,Happens2EventMoment(Action2AgentActionType(Self1Agent(X),U),W)))).","DCEC_RULE_14"),
    ])
    nonSimultaneous=dict([
        ("|| Boolean(U) isValid(U) isValid(Implies2BooleanBoolean(U,V))* Boolean(V) -> isValid(V).","MODUS_PONENS"),
        ("|| Boolean(U) isValid(U) isValid(V) Boolean(V) -> isValid(And2BooleanBoolean(U,V))*.","CONJUNCTION_INTRODUCTION"),
        ("|| Agent(U) isValid(K3AgentMomentBoolean(U,V,W))* Moment(V) Boolean(W) -> isValid(W).","DCEC_RULE_4"),
        ("|| Moment(U) Boolean(V) Boolean(W) -> isValid(C2MomentBoolean(U,Implies2BooleanBoolean(Iff2BooleanBoolean(V,W),Implies2BooleanBoolean(Not1Boolean(V),Not1Boolean(W)))))*.","DCEC_RULE_9"),
        ("|| Moment(U) Agent(V) Boolean(W) -> isValid(C2MomentBoolean(U,Implies2BooleanBoolean(K3AgentMomentBoolean(V,U,W),B3AgentMomentBoolean(V,U,W))))*.","DCEC_RULE_2"),
        ("|| Moment(U) Agent(V) Boolean(W) -> isValid(C2MomentBoolean(U,Implies2BooleanBoolean(P3AgentMomentBoolean(V,U,W),K3AgentMomentBoolean(V,U,W))))*.","DCEC_RULE_1"),
        ("|| Moment(U) Boolean(V) Boolean(W) Boolean(X) -> isValid(C2MomentBoolean(U,Implies2BooleanBoolean(Implies2BooleanBoolean(And2BooleanBoolean(V,W),X),Implies2BooleanBoolean(V,Implies2BooleanBoolean(W,X)))))*.","DCEC_RULE_10"),
        ("|| Agent(U) isValid(S4AgentAgentMomentBoolean(U,V,W,X)) Agent(V) Moment(W) Boolean(X) -> isValid(B3AgentMomentBoolean(V,W,B3AgentMomentBoolean(U,W,X)))*.","DCEC_RULE_12"),
        ("|| Agent(U) isValid(B3AgentMomentBoolean(U,V,W)) isValid(B3AgentMomentBoolean(U,V,X)) Moment(V) Boolean(W) Boolean(X) -> isValid(B3AgentMomentBoolean(U,V,And2BooleanBoolean(W,X)))*.","DCEC_RULE_11B"),
        ("|| Agent(U) isValid(B3AgentMomentBoolean(U,V,Implies2BooleanBoolean(W,X)))* isValid(B3AgentMomentBoolean(U,V,W)) Moment(V) Boolean(W) Boolean(X) -> isValid(B3AgentMomentBoolean(U,V,X)).","DCEC_RULE_11A"),
        ("|| Boolean(U) isValid(Iff2BooleanBoolean(U,V)) Boolean(V) Agent(W) Agent(X) Boolean(Y) -> isValid(Iff2BooleanBoolean(O4AgentMomentBooleanBoolean(W,X,U,Y),O4AgentMomentBooleanBoolean(W,X,V,Y)))*.","DCEC_RULE_15"),
        ("|| Agent(U) isValid(I3AgentMomentBoolean(U,V,Happens2EventMoment(Action2AgentActionType(Self1Agent(U),W),X))) Moment(V) ActionType(W) Moment(X) -> isValid(P3AgentMomentBoolean(U,V,Happens2EventMoment(Action2AgentActionType(Self1Agent(U),W),X)))*.","DCEC_RULE_13"),
        ("|| Moment(U) Boolean(V) Boolean(W) isValid(Lessorequal2MomentMoment(X,Y)) Moment(X) Moment(Z) isValid(Lessorequal2MomentMoment(Z,Y)) Moment(Y) -> isValid(C2MomentBoolean(U,Implies2BooleanBoolean(C2MomentBoolean(X,Implies2BooleanBoolean(V,W)),Implies2BooleanBoolean(C2MomentBoolean(Z,V),C2MomentBoolean(Y,W)))))*.","DCEC_RULE_7"),
        ("|| Moment(U) Agent(V) Boolean(W) Boolean(X) Moment(Y) isValid(Lessorequal2MomentMoment(Y,Z)) isValid(Lessorequal2MomentMoment(X1,Z)) Moment(X1) Moment(Z) -> isValid(C2MomentBoolean(U,Implies2BooleanBoolean(B3AgentMomentBoolean(V,Y,Implies2BooleanBoolean(W,X)),Implies2BooleanBoolean(B3AgentMomentBoolean(V,X1,W),B3AgentMomentBoolean(V,Z,X)))))*.","DCEC_RULE_6"),
        ("|| Moment(U) Agent(V) Boolean(W) Boolean(X) Moment(Y) isValid(Lessorequal2MomentMoment(Y,Z)) isValid(Lessorequal2MomentMoment(X1,Z)) Moment(X1) Moment(Z) -> isValid(C2MomentBoolean(U,Implies2BooleanBoolean(K3AgentMomentBoolean(V,Y,Implies2BooleanBoolean(W,X)),Implies2BooleanBoolean(K3AgentMomentBoolean(V,X1,W),K3AgentMomentBoolean(V,Z,X)))))*.","DCEC_RULE_5"),
        ("|| Moment(U) isValid(Lessorequal2MomentMoment(U,V))* isValid(C2MomentBoolean(U,W))* isValid(Lessorequal2MomentMoment(V,X)) Moment(V) Moment(X) isValid(Lessorequal2MomentMoment(X,Y)) Moment(Y) Boolean(W) Agent(Z) Agent(X1) Agent(X2) -> isValid(K3AgentMomentBoolean(Z,V,K3AgentMomentBoolean(X1,X,K3AgentMomentBoolean(X2,Y,W))))*.","DCEC_RULE_3"),
        ("|| Agent(U) isValid(B3AgentMomentBoolean(U,V,W)) isValid(B3AgentMomentBoolean(U,V,O4AgentMomentBooleanBoolean(Self1Agent(U),V,W,Happens2EventMoment(Action2AgentActionType(Self1Agent(U),X),Y))))* isValid(O4AgentMomentBooleanBoolean(U,V,W,Happens2EventMoment(Action2AgentActionType(Self1Agent(U),X),Y))) isValid(Lessorequal2MomentMoment(V,Y)) Moment(V) Boolean(W) ActionType(X) Moment(Y) -> isValid(K3AgentMomentBoolean(U,V,I3AgentMomentBoolean(Self1Agent(U),V,Happens2EventMoment(Action2AgentActionType(Self1Agent(U),X),Y)))).","DCEC_RULE_14")
    ])
    def __init__(self,inputProof,container,isSimultaneous, symbolReverter):
        #inputProof is the raw spass proof output
        #container is an empty DCECContainer with the necessary namespace
        inputProof=inputProof.split("\n")
        #split the proof
        for x in range(0,len(inputProof)):
            idStart=inputProof[x].find("[")
            idEnd=inputProof[x].find("] ")+2
            #find the start and end of the premise ids
            if inputProof[x].rfind(":",0,idEnd) == inputProof[x].find(":",0,idEnd):
                premiseStart=idEnd-2
                #if there were no premises be prepared to have none
            else:
                premiseStart=inputProof[x].rfind(":",0,idEnd)+1
                #otherwise be prepared to cut off the rule
            inputProof[x]=[inputProof[x][:idStart],filter(None, inputProof[x][premiseStart:idEnd-2].split(",")),inputProof[x][idEnd:]]
            #set up a tuple with the first index the string for the line number
            #with the second index being the list of line numbers for premises
            #with the third index being the actual line
        
        for line in inputProof:
            if line[2][-4:]=='-> .':
                line[2]="(leads_to_conclusion "+toSNotation(line[2],container.namespace.sorts, symbolReverter)+")"
            else:
                line[2]=toSNotation(line[2],container.namespace.sorts,symbolReverter)
            if isSimultaneous:
                if line[2] in self.simultaneous:
                    line[2]=self.simultaneous[line[2]]
            else:
                if line[2] in self.nonSimultaneous:
                    line[2]=self.nonSimultaneous[line[2]]
        x=len(inputProof)-1
        while x>=0:
            if inputProof[x][1]==[] and inputProof[x][2]=='':
                inputProof.pop(x)
            else:
                for y in range(0,len(inputProof[x][1])):
                    inputProof[x][1][y]=inputProof[x][1][y].split(".")[0]
            x-=1
        idLookup=dict()
        for line in inputProof:
            idLookup[line[0]]=line[2]
        for line in inputProof:
            x=len(line[1])-1
            while x>=0:
                if not (line[1][x] in idLookup.keys()):
                    line[1].pop(x)
                x-=1
        usedLines=set()
        x=len(inputProof)-1
        while x>=0:
            y=len(inputProof[x][1])-1
            while y>=0:
                if idLookup[inputProof[x][1][y]]==inputProof[x][2]:
                    for z in inputProof:
                        if z[0]==inputProof[x][1][y]:
                            inputProof[x][1]+=z[1]
                            break
                    inputProof[x][1].pop(y)
                    y=len(inputProof[x][1])
                else:
                    usedLines.add(inputProof[x][1][y])
                y-=1
            x-=1
            inputProof[x][1]=list(set(inputProof[x][1]))
        usedLines.add(inputProof[-1][0])
        x=len(inputProof)-1
        while x>=0:
            if not inputProof[x][0] in usedLines:
                inputProof.pop(x)
            x-=1
        self.proofDict=dict()
        for line in inputProof:
            premises=[]
            for p in line[1]:
                premises.append(idLookup[p])
            self.proofDict[line[2]]=premises
        """
        self.proofTree=self.stratify("(leads_to_conclusion )")
    #return a tuple, first index the leads to conclusion, second index is a list of reasons that are recursive
    def stratify(self,currentStr):
        nextLayer=copy.deepcopy(self.proofDict[currentStr])
        if nextLayer==None:
            nextLayer=[]
        print currentStr,"  :::  ",nextLayer
        for x in range(0,len(nextLayer)):
            nextLayer[x]=self.stratify(nextLayer[x])
        return (currentStr,nextLayer)
    def printPrettyProof(self,pTree=None,indents=""):
        if pTree==None:
            pTree=self.proofTree
        output=indents+pTree[0]+"\n"
        for x in pTree[1]:
            output+=self.printPrettyProof(x,indents+"\t")
        return output
        """