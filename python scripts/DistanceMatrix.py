import numpy as np
import math
from math import *
from pandas import *
n=int(input("please enter the number items in the data set"))
m=[]
out=[]
for i in range (0,n*2):
    m.append(float(input()))
    
m=np.array(m)
m=m.reshape(n,2)
algo=int(input("select algorithm enter 0-->euclidean, 1-->manhattan"))
if algo==0:
    for i in range (n):
        for j in range (n):
            out.append(round( sqrt( (m[i][0]-m[j][0])**2 + (m[i][1]-m[j][1])**2 ),2) )
elif algo==1:
    for i in range (n):
        for j in range (n):
            out.append(abs(m[i][0]-m[j][0])+abs(m[i][1]-m[j][1]))
out=np.array(out)
out=out.reshape(n,n)
#print(out)
print (pandas.DataFrame(out))








#ecluduan =root((x2-x1)^2 + (y2-y1)^2)
#manhatten = |x1-x2| + |y1-y2|
"""
2
10
2
5
8
4
5
8
7
5
6
4
1
2
4
9
"""
