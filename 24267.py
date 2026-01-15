def isPrime(num):
    if num < 2:
        return False
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True

n = int(input())

for _ in range(n):
    N = int(input())
    while not isPrime(N):
        N += 1
    print(N)
