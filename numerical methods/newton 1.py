import math
from math import *
from sympy import *
from prettytable import PrettyTable
t = PrettyTable()
fX=input("f(x) = ")
a=input("x = ")
tol=input("tol= ")
n=input("N= ")
x = Symbol('x')
fbarX=sympify(fX).diff(x)
print(fbarX)
fxx=round(eval(fX.replace("x",str(a))),4)
t.field_names = ["i", "xi", "f(xi)", "f'(xi)"]
for i in range (int(n)):
    if abs(fxx) >= 0.01:
        fxx=round(eval(fX.replace("x",str(a))),4)
        fbarxx=round(eval(str(fbarX).replace("x",str(a))),4)
        t.add_row([i+1,round(float(a),4),round(float(fxx),4),round(float(fbarxx),4)])
        a=float(a)-(fxx/fbarxx)
print(t)
print("root = ",fxx )
