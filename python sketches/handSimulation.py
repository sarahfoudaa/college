interArrivalTimes=[]
serviceTimes=[]
n = int (input("enter number of customers"));
print("please enter the inter arrival times for the customers");
for i in range(n):
    interArrivalTimes.append(int(input()));
print("please enter the service times for the customers");
for i in range(n):
    serviceTimes.append(int(input()));
k=0;
arrivalTime=[k]*(n+1)
timeServiceBegins=[k]*(n+1)
timeServiceEnds=[k]*n
waitingTime=[k]*n
customersInQueue=[k]*n
timeCustomerSpendsInSystem=[k]*n
serverIdleTime=[k]*n

sumInterArivalTime=0
sumServiceTimes=0
sumArrivalTime=0
sumTimeServiceBegins=0
sumTimeServiceEnds=0
sumWaitingTime=0
sumCustomersInQueue=0
sumTimeCustomerSpendsInSystem=0
sumServerIdleTime=0
    

for i in range (n):
    arrivalTime[i]=arrivalTime[i-1]+interArrivalTimes[i];

for i in range (n):
    timeServiceEnds[i]=timeServiceBegins[i]+serviceTimes[i];
    timeServiceBegins[i+1]=max(arrivalTime[i+1],timeServiceEnds[i]);
    waitingTime[i]=timeServiceBegins[i]-arrivalTime[i];
    
for i in range (n):
    if(timeServiceBegins[i]>arrivalTime[i]):
        if(arrivalTime[i]>timeServiceBegins[i-1]):
            customersInQueue[i]=max(1,customersInQueue[i-1]-1);
        else:
            if(arrivalTime[i]<timeServiceEnds[i-2]):
                customersInQueue[i]=min(2,customersInQueue[i-1]+1);
            else:
               customersInQueue[i]=1;
    else:
        if(arrivalTime[i]>timeServiceBegins[i-1]):
            customersInQueue[i]=max(0,customersInQueue[i-1]-1);
        else:
            customersInQueue[i]=customersInQueue[i-1];
            
for i in range (n):
    timeCustomerSpendsInSystem[i]=timeServiceEnds[i]-arrivalTime[i];
    serverIdleTime[i]=timeServiceBegins[i]-timeServiceEnds[i-1];

serverIdleTime[0]=arrivalTime[0];
waitedCustomer=0
waitedTime=0
for i in range (n):
    sumInterArivalTime+=interArrivalTimes[i];
    sumServiceTimes+=serviceTimes[i];
    sumArrivalTime+=arrivalTime[i];
    sumTimeServiceBegins+=timeServiceBegins[i];
    sumTimeServiceEnds+=timeServiceEnds[i];
    sumWaitingTime+=waitingTime[i];
    sumCustomersInQueue+=customersInQueue[i];
    sumTimeCustomerSpendsInSystem+=timeCustomerSpendsInSystem[i];
    if(waitingTime[i]>0):
        waitedCustomer+=1;
        waitedTime+=waitingTime[i];

for i in range (n):
    sumServerIdleTime+=serverIdleTime[i];


averageWaitingTime=sumWaitingTime/n;
probabilityOfWaiting=waitedCustomer/n;
probabilityOfServerIdling=sumServerIdleTime/sumTimeCustomerSpendsInSystem;
averageServiceTime=sumServiceTimes/n;
averageInterArrivalTime=sumInterArivalTime/(n-1);
averageWaitingTime=waitedTime/waitedCustomer;
averageTimeInTheSystem=sumTimeCustomerSpendsInSystem/n;


print("|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------|");
print("| inter arrival time | arrival time | service time | time service begin | waiting time | customer in queue | sevic ends | time customer spends in system | server idle time |");
print("|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------|");
for i in range (n):
    print("|",interArrivalTimes[i] ," "*(17-len(str(interArrivalTimes[i]))),"|", arrivalTime[i]," "*(11-len(str(arrivalTime[i]))),"|",serviceTimes[i]," "*(11-len(str(serviceTimes[i]))),"|",timeServiceBegins[i]," "*(17-len(str(timeServiceBegins[i]))),"|",waitingTime[i]," "*(11-len(str(waitingTime[i]))),"|",customersInQueue[i]," "*(16-len(str(customersInQueue[i]))),"|",timeServiceEnds[i]," "*(9-len(str(timeServiceEnds[i]))),"|",timeCustomerSpendsInSystem[i]," "*(29-len(str(timeCustomerSpendsInSystem[i]))),"|",serverIdleTime[i]," "*(15-len(str(serverIdleTime[i]))),"|");

print("|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------|");
print("|",sumInterArivalTime ," "*(17-len(str(sumInterArivalTime))),"|", sumArrivalTime," "*(11-len(str(sumArrivalTime))),"|",sumServiceTimes," "*(11-len(str(sumServiceTimes))),"|",sumTimeServiceBegins," "*(17-len(str(sumTimeServiceBegins))),"|",sumWaitingTime," "*(11-len(str(sumWaitingTime))),"|",sumCustomersInQueue," "*(16-len(str(sumCustomersInQueue))),"|",sumTimeServiceEnds," "*(9-len(str(sumTimeServiceEnds))),"|",sumTimeCustomerSpendsInSystem," "*(29-len(str(sumTimeCustomerSpendsInSystem))),"|",sumServerIdleTime," "*(15-len(str(sumServerIdleTime))),"|");
print("|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------|");
print("|",sumInterArivalTime/n ," "*(17-len(str(sumInterArivalTime/n))),"|", sumArrivalTime/n," "*(11-len(str(sumArrivalTime/n))),"|",sumServiceTimes/n," "*(11-len(str(sumServiceTimes/n))),"|",sumTimeServiceBegins/n," "*(17-len(str(sumTimeServiceBegins/n))),"|",sumWaitingTime/n," "*(11-len(str(sumWaitingTime/n))),"|",sumCustomersInQueue/n," "*(16-len(str(sumCustomersInQueue/n))),"|",sumTimeServiceEnds/n," "*(9-len(str(sumTimeServiceEnds/n))),"|",sumTimeCustomerSpendsInSystem/n," "*(29-len(str(sumTimeCustomerSpendsInSystem/n))),"|",sumServerIdleTime/n," "*(15-len(str(sumServerIdleTime/n))),"|");
print("|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------|");
print("1) average waiting time = ",averageWaitingTime);
print("2) probability of waiting = ",probabilityOfWaiting);
print("3) probability of server idling",probabilityOfServerIdling);
print("4) average service time = ",averageServiceTime);
print("5) average inter-arrival time = ",averageInterArrivalTime);
print("6) average waiting time (for those that do wait = ",averageWaitingTime);
print("7) average time in the system = ",averageTimeInTheSystem);
