import math
from math import *
from prettytable import PrettyTable
t = PrettyTable()
f=input("f(x) = ")
A=input("x0 = ")
tol=input("tolerance= ")
g=f+"+x"
n=input("n = ")
fx=round(eval(f.replace("x",str(A))),4)
t.field_names = ["i","x","fx","gx"]
for i in range (int(n)):
    if abs(fx) >= float(tol):
        fx=round(eval(f.replace("x",str(A))),4)
        gx=round(eval(g.replace("x",str(A))),4)
        t.add_row([i+1,A,fx,gx])
        A=gx
print(t)
print("root = ",gx )























#x*x-2*x-3
#sin(x)-x*x*x
#x*x-3
