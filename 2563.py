rows = 100
cols = 100

arr = [[0 for j in range(cols)] for i in range(rows)]

num = int(input())

for i in range(num):
    XandY = input().split()
    x = int(XandY[0])
    y = int(XandY[1])
    
    for j in range(x, x + 10):
        for k in range(y, y + 10):
            arr[j][k] = 1

number = 0
for i in range(100):
    for j in range(100):
        if arr[i][j] == 1:
            number += 1
            
print(number)