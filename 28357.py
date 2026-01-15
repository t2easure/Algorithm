def candy(v, X):
    candies = 0
    for i in v:
        if i > X:
            candies += i - X
    return candies

def binary_search(v, K):
    left = 0
    right = max(v)
    result = right

    while (left <= right):
        mid = (left + right) // 2
        candies = candy(v, mid)
        if (candies <= K):
            result = mid
            right = mid - 1
        else:
            left = mid + 1
    return result

N, K = map(int, input().split())
scores = list(map(int, input().split()))

print(binary_search(scores, K))