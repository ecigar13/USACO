import math
inFile=open('crossings.in','r')
out=open('crossings.out','w')


## This solution doesn't address time limit exceeded problem
cows=int(inFile.readline())
allCows=[]
cow_safe=[1 for i in range(cows)]

count=0
##read in the data
for i in range(cows):
    a=inFile.readline()
    start, stop = a.split()
    allCows.append([int(start),int(stop)])

for cow1 in range(cows):
    if(cow_safe[cow1]== -1 ):
        continue
    for cow2 in range(cows):
        if(cow1==cow2):
            continue
        diff1=allCows[cow1][0]> allCows[cow2][0] and allCows[cow1][1]> allCows[cow2][1]
        diff2=allCows[cow1][0]< allCows[cow2][0] and allCows[cow1][1]< allCows[cow2][1]
        
        if not(diff1 or diff2):
            #print(allCows[cow1], allCows[cow2])
            cow_safe[cow1]=-1
            cow_safe[cow2]=-1
    if cow_safe[cow1]==1 :
        count+=1

print(count)
out.write(str(count))
inFile.close()
out.close()
