import math
inFile=open('crossings.in','r')
out=open('crossings.out','w')

cows=int(inFile.readline())
collide=[]
nocollide=[]

## 2 arrays, move the item with no collision to nocollide
## leave item with collision
## item with collision will initially have all the cows
## at the end, print items remaining in collision

for i in range(cows):
    a=inFile.readline()
    start, stop = a.split()
    collide.append((int(start),int(stop)))

    
    
for i in range(cows):
    if(collided[i]==1):
        continue;
    for j in range(cows):
        if(collided[j]==1 or j==i):
            continue;
        diff1=collide[i][1]-collide[j][1]
        diff2=collide[i][0]-collide[j][0]
        #print(diff1, diff2)
        diff1=math.copysign(1,diff1)
        diff2=math.copysign(1,diff2)
        if(diff1/diff2 < 0):
            break
        else:
            nocollide.append(collide.pop(i));
        
count=0;
for i in collided:
    if(collided[i]==1):
        count+=1;


out.write(str(count))
inFile.close()
out.close()
