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
for time in range(0,11000):

    while curcow < n and time <= deadline[curcow][1]:
        heapq.heappush(time_array, -deadline[curcow][0])  #wrap data
        curcow+=1 


    if(len(time_array) > 0):
        temp = heapq.heappop(time_array)
        answer -= temp     #unwrap data

out.write(str(answer))
inFile.close()
out.close()
