N, M = map(int, input().split())

num = 0

S = []

for i in range(N):
    S.append(input())
    
for i in range(M):
    string = input()
    if string in S:
        num += 1

print(num)