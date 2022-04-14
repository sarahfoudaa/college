import math
from math import *
f=input("f(x) = ")
A=input("A = ")
B=input("B = ")
n=int(round(log((float(B)-float(A))/0.01,2),0))
c=(int(A)+int(B))/2
fC=round(eval(f.replace("x",str(c))),4)
print ("|-------------------------------------------------------------------------------|")
print ("|i      |a          |b          |c          |f(a)       |f(b)       |f(c)       |")
print ("|-------------------------------------------------------------------------------|")
for i in range (n):
    if abs(fC) >= 0.01:
        fA=round(eval(f.replace("x",str(A))),4)
        fB=round(eval(f.replace("x",str(B))),4)
        C=round((float(A)+float(B))/2,4)
        fC=round(eval(f.replace("x",str(C))),4)
        a=A
        b=B
        root="   "
        if (float(fC)*float(fA)) < 0:
            B=C
            root="A&C"
        elif(float(fC)*float(fB)) < 0:
            A=C
            root="C&B"

        print("|",i+1," "*(4-len(str(i+1))),"|",a," "*(8-len(str(a))),"|",b," "*(8-len(str(b))),"|",C," "*(8-len(str(C))),"|",fA," "*(8-len(str(fA))),"|",fB," "*(8-len(str(fB))),"|",fC," "*(8-len(str(fC))),"|",root,"  |")

        
print ("|-------------------------------------------------------------------------------|")
print("root = ",C )




#x*x-2*x-3
#sin(x)-x*x*x
#x*x-3
