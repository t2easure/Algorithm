n, k = map(int, input().split())

number = list(map(int, input().split()))
    
number.sort()
print(number[k - 1])