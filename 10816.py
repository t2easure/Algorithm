import sys

N = int(sys.stdin.readline())
Numlist = list(map(int, sys.stdin.readline().split()))

M = int(sys.stdin.readline())
answerList = list(map(int, sys.stdin.readline().split()))

num_count = {}
for num in Numlist:
    if num in num_count:
        num_count[num] += 1
    else:
        num_count[num] = 1

result = []
for answer in answerList:
    result.append(num_count.get(answer, 0))
    
print(' '.join(result))