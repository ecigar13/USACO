inFile=open('skidesign.in','r')
out=open('skidesign.out','w')


data=[]
list_len=int(inFile.readline())
for line in inFile:
    data.append(int(line))

data.sort()


shortestHill=data[0]
tallestHill=data[list_len-1]

solution=[]
cost=0;
for start_range in range(data[0],data[list_len-1]):
    end_range=start_range+17
    if(end_range > tallestHill):
        break;

    for j in data:
        
        if(j< start_range):
            cost+= (start_range-j)**2
        elif(j>end_range):
            cost+=(j-end_range)**2
        else: continue

 

    solution.append(cost)
    cost=0;
    

solution.sort()
out.write(str(solution[0]))
inFile.close()
out.close()
