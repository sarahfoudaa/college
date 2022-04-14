import matplotlib.pyplot as plt

w1=float(input("enetr w1: "))
w2=float(input("enetr w2: "))
bias=int(input("enter bias: "))
arr =[[0,0],[0,1],[1,0],[1,1]]
print("-------------")
print("| x , y |class|")
print("-------------")
c1=0
c2=0
for i in range(4):
    x=arr[i][0]
    y=arr[i][1]
    f=w1*x+w2*y-bias    
    if f>0:
        boo=1
        plt.plot(x,y,color='black',marker='o',markerfacecolor='blue',markersize=12)
        c1=c1+1
        point1 = [0, y+0.5]
        point2 = [x+0.5,0]
        print("|",x,",",y,"|",boo,"|")
    else:
        boo=0
        plt.plot(x,y,color='black',marker='o',markerfacecolor='green',markersize=12)
        c2=c2+1
        point3 = [0, y+0.5]
        point4 = [x+0.5,0]
        print("|",x,",",y,"|",boo,"|")
print("-------------")
if c1 < c2:
    x_values = [point1[0], point2[0]]
    y_values = [point1[1], point2[1]]
    plt.plot(x_values, y_values)
else :
    x_values = [point3[0], point4[0]]
    y_values = [point3[1], point4[1]]
    plt.plot(x_values, y_values)
    
plt.ylim(0,3)
plt.xlim(0,3)

plt.show()
