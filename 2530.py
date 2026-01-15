h, m, s = map(int, input().split())
second = int(input())

while(second >= 3600):
    h += 1
    second -= 3600
while(second >= 60):
    m += 1
    second -= 60
s += second
    
while s >= 60:
    s -= 60
    m += 1
while m >= 60:
    m -= 60
    h += 1
while h >= 24:
    h -= 24
    
print(h, m, s)