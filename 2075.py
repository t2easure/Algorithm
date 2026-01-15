import heapq

n = int(input())

heap = []

for i in range(n):
    inputs = list(map(int, input().split()))

    for j in inputs:
        if n > len(heap):
            heapq.heappush(heap, j)
        else:
            if j > heap[0]:
                heapq.heappop(heap)
                heapq.heappush(heap, j)
print(heap[0])