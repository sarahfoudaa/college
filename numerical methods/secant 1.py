import math
from math import *
f=input("f(x) = ")
A=input("A = ")
B=input("B = ")
tol=input("tolerance= ")
n=int(round(log((float(B)-float(A))/float(tol),2),0))
c=float(B)-(eval(f.replace("x",str(B))))*((float(B)-float(A))/((eval(f.replace("x",str(B))))-(eval(f.replace("x",str(A))))))
fC=eval(f.replace("x",str(c)))
print ("|-------------------------------------------------------------------------------|")
print ("|i      |a          |b          |c          |f(a)       |f(b)       |f(c)       |")
print ("|-------------------------------------------------------------------------------|")
for i in range (n):
    if abs(fC) >= float(tol):
        fA=round(eval(f.replace("x",str(A))),4)
        fB=round(eval(f.replace("x",str(B))),4)
        C=round(float(B)-fB*((float(B)-float(A))/(fB-fA)),4)
        fC=round(eval(f.replace("x",str(C))),4)
        print("|",i+1," "*(4-len(str(i+1))),"|",A," "*(8-len(str(A))),"|",B," "*(8-len(str(B))),"|",C," "*(8-len(str(C))),"|",fA," "*(8-len(str(fA))),"|",fB," "*(8-len(str(fB))),"|",fC," "*(8-len(str(fC))),"|")
        A=B
        B=C
    else:
        print(c)
        exit()
print ("|-------------------------------------------------------------------------------|")
print("root = ",C )









#x*x-2*x-3
#sin(x)-x*x*x
#x*x-3
