import math
inFile=open('crossings.in','r')
out=open('crossings.out','w')

cows=int(inFile.readline())
collided=[0 for i in range(cows)] #0= haven't checked, 1 = no collision, 2 = collide
coordinates=[]
for i in range(cows):
    a=inFile.readline()
    start, stop = a.split()
    coordinates.append((int(start),int(stop)))
    
for i in range(cows):
    if(collided[i]==1):
        continue;
    for j in range(cows):
        if(collided[j]==1 or j==i):
            continue;
        diff1=coordinates[i][1]-coordinates[j][1]
        diff2=coordinates[i][0]-coordinates[j][0]
        #print(diff1, diff2)
        diff1=math.copysign(1,diff1)
        diff2=math.copysign(1,diff2)
        if(diff1/diff2 < 0):
            collided[i], collided[j]=2,2;
        else:
            collided[i] = 1;
count=0;
for i in collided:
    if(collided[i]==1):
        count+=1;


out.write(str(count))
inFile.close()
out.close()
