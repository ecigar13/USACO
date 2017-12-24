## python code runs slower than C++

inFile = open('mirror.in', 'r')
out = open('mirror.out', 'w')

temp1, temp2 = inFile.readline().split();
n, m = int(temp1), int(temp2)
arr = [['a' for r in range(m)] for c in range(n)]

answer = 0


## direction: w,a,s,d. think of the keyboard
## return char: w,a,s,d
def findDir(dirIn, mirror):
    if dirIn == 'w':
        if mirror == '\\':
            return 'a'
        if mirror == '/':
            return 'd'
    if dirIn == 's' :
        if mirror == '\\':
            return 'd'
        if mirror == '/':
            return 'a'
    if dirIn == 'a' :
        if mirror == '\\':
            return 'w'
        if mirror == '/':
            return 's'
    if dirIn == 'd' :
        if mirror == '\\':
            return 's'
        if mirror == '/':
            return 'w'



## take in direction and the mirror it hits first
def findNumReflection(dir, r, c):
    global answer, n, m
    count = 0;
    ## while index not out of bound

    while not (r < 0 or r >= n or c < 0 or c >= m):
        ## call function findDir
        temp = findDir(dir, arr[r][c])
        count += 1
        #print(count, temp, r, c)
        if temp == 'w':
            r -= 1
        if temp == 'a':
            c -= 1
        if temp == 's':
            r += 1
        if temp == 'd':
            c += 1
        dir = temp

    if (count > answer):
        answer = count


for r in range(n):
    temp = inFile.readline()
    for c in range(m):
        arr[r][c] = temp[c]

for c in range(m):
    findNumReflection('s', 0, c)
    findNumReflection('w', n - 1, c)

for r in range(n):
    findNumReflection('d', r, 0)
    findNumReflection('a', r, m - 1)

out.write(str(answer))
inFile.close()
out.close()
