a, b = map(int, input().split())
Alist = list(map(int, input().split()))
Blist = list(map(int, input().split()))

for i in range(b):
    Alist.append(Blist[i])

Alist.sort()
for i in range(a + b):
    print(Alist[i], end=' ')