n = int(input())

max = 0

for i in range(n):
    a, b, c = map(int, input().split())
    if a == b and b == c:
        result = 10000 + a * 1000
    elif a == b:
        result = 1000 + a * 100
    elif b == c:
        result = 1000 + b * 100
    elif a == c:
        result = 1000 + a * 100
    else:
        maxnum = a
        if a < b:
            if b < c:
                maxnum = c
            else:
                maxnum = b
        elif a < c:
            maxnum = b
        result = maxnum * 100
    
    if result > max:
        max = result
        
print(max)