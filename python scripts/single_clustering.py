import numpy as np
import math
from math import *
from pandas import *
n=int(input("please enter the number items in the data set"))
m=[]
out=[]
minn = 9999
for i in range (0,n*2):
    m.append(float(input()))

m=np.array(m)
m=m.reshape(n,2)
#applying ecludean
for i in range (n):
    for j in range (n):
        x = round( sqrt( (m[i][0]-m[j][0])**2 + (m[i][1]-m[j][1])**2 ),2) 
        out.append(x)
        if x < minn and x > 0.0:
            minn = x
            mini=i
            minj=j
out=np.array(out)
out=out.reshape(n,n)
print(pandas.DataFrame(out))

print(minn)
print(mini)
print(minj)
#single linkage
# merge the col and rows of the smallest value
for l in range (n-2):
    minn = 99999
    for i in range(n-l):
        for j in range(n-l):
            if out[i][j]< minn and out[i][j] != 0.0:
                minn=out[i][j]
                mini = i
                minj= j
            
    print(minn)
    print(mini)
    print(minj)
    if mini <= minj:
            col = mini
    else:
            col = minj
    print(col)
    #col
    for k in range (n-l):
            if out[k][mini] <= out[k][minj] and out[k][minj]!=0.0 and out[k][mini]!=0.0:
                    out[k][col] = out[k][mini]
            elif out[k][minj] < out[k][mini]and out[k][minj]!=0.0 and out[k][mini]!=0.0:
                    out[k][col] = out[k][minj]
    #row
    for k in range (n-l):
            if out[mini][k] <= out[minj][k]and out[k][minj]!=0.0 and out[k][mini]!=0.0:
                    out[col][k] = out[mini][k]
            elif out[minj][k] < out[mini][k]and out[k][minj]!=0.0 and out[k][mini]!=0.0:
                    out[col][k] = out[minj][k]


    out = np.delete(out, minj, 0)#roww
    out = np.delete(out, minj, 1)#col

    print (pandas.DataFrame(out))

#print(out)
#print (pandas.DataFrame(out))

"""
for i in range (n):
    for j in range (n):
        if i!=mini and i != minj and j!=mini and j!= minj:
            out[i][j]=out[i][j]

for i in range (n):
    for j in range (i):
        out[i][j] =out[j][i]  
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
