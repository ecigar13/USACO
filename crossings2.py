import math
inFile=open('crossings.in','r')
out=open('crossings.out','w')

## this solution uses the first step of radix sort

## create array large enough to do radix sort
## read each line and sort right away
## create a second array (of safe cows)
## array is sorted, so just read from left to right and make sure none cross
## if the next one crosses several ones, then go back and remove them.

MAXSIZE=2000002
OFFSET=1000001

stop = [0]*MAXSIZE
cows=int(inFile.readline())
for i in range(cows):
    temp1, temp2 = inFile.readline().split()
    start, stopt=int(temp1)+OFFSET,int(temp2)+OFFSET
    stop[stopt]=start

safeCowStop=[0]*cows
safeInsert=0
maxStop=0

for i in range(MAXSIZE):
    if stop[i] > 0:
        if maxStop < stop[i]:
            safeCowStop[safeInsert] = stop[i]
            maxStop=stop[i]
            safeInsert+=1
        else:
            while safeInsert > 0 and safeCowStop[safeInsert-1] > stop[i]:
               safeInsert-=1
        


print(safeInsert)
out.write(str(safeInsert))
inFile.close()
out.close()
