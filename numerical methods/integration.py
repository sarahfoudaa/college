from math import *
from prettytable import PrettyTable
t=PrettyTable()
ct=PrettyTable()
t.field_names = ["x","f(x)"]
ct.field_names = ["x","f(x)"]
a=input("a= ")
b=input("b= ")
h=input("h= ")
f=input("f(x)= ")
f=f.replace("e",str(2.718281828459045))#for exponential
sumofF=0;sumofCT=0;sumofCS=0
print("midpoint = ",round((float(b)-float(a))*eval(f.replace("x",str((float(b)+float(a))/2))),5))
print("trapezoidal = ",round((float(b)-float(a))*( float( eval(f.replace("x",str(a)))+eval(f.replace("x",str(b))))/float(2)),5))
print("simpson = ",round(((float(b)-float(a))/6)*(float(eval(f.replace("x",str(a)))+eval(f.replace("x",str(b))))+4*eval(f.replace("x",str((float(b)+float(a))/2)))),5))
for i in range (int(a)+8,int(float(b)/float(h)+1)):#composit midpoint
    x=i*float(h)-float(h)/2     
    ff=eval( f.replace ("x",str(x)))
    t.add_row([x,ff])
    sumofF=sumofF+ff
for i in range (int(a)+2,int(float(b)/float(h)+1)):#composite trapezoidal & simpson
    y=(i)*float(h)
    fy=eval( f.replace ("x",str(y)))
    ct.add_row([y,fy])
    if(i!=a and i!=(int(float(b)/float(h)))):
        sumofCT=sumofCT+2*fy
        if(i%2==0):
            sumofCS=sumofCS+2*fy
        else:
            sumofCS=sumofCS+4*fy
            
    else:
        sumofCT=sumofCT+fy
        sumofCS=sumofCS+fy
print(t)
print("composite midpoint = ",round(float(h)*sumofF,5))
print(ct)
print("composite trapezoidal = ",round((float(h)/2)*sumofCT,5))
print("composite simposon = ",round((float(h)/3)*sumofCS,5))
