inFile=open('msched.in','r')
out=open('msched.out','w')

import heapq
## inverted min heap for python
## to create a max heap

deadline=[]
n=int(inFile.readline())
time_array=[]

for i in range(n):
    milk, time = inFile.readline().split()
    milk, time = int(milk), int(time)
    deadline.append([milk, time]) 
deadline = sorted(deadline,key=lambda tup: tup[1])
print(deadline)
curcow=0
answer=0
for time in range(deadline[len(deadline)-1][1]):  #last deadline
    
    while curcow < n:
        temp=deadline[curcow]
        temp=[-temp[0],temp[1]]
        heapq.heappush(time_array, temp)  #wrap data
        curcow+=1 

    if(len(time_array) > 0):
        temp = heapq.heappop(time_array)
        answer -= temp[0]     #unwrap data

    print(time_array,answer, time)

    for item in time_array:
        if item[1] <= time:
            time_array.remove(item)
        if len(time_array)==0:
           break;


    

out.write(str(answer))
inFile.close()
out.close()
