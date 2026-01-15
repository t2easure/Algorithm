import heapq
import sys

input = sys.stdin.readline # 표준 입력에서 한 줄씩 읽기기

arr = []
result = []

N = int(input().strip()) # 첫 줄에서 연산의 개수 N 읽음 

for _ in range(N):
    x = int(input().strip()) * (-1) # 다음 N 개의 줄에서 각 연산에 대한 입력 x 읽음음
    if x != 0:
        heapq.heappush(arr, x)
    else:
        if not arr:
            result.append("0\n")
        else:
            result.append(f"{heapq.heappop(arr) * (-1)}\n")

sys.stdout.write("".join(result)) # 모든 결과를 한 번에 출력
