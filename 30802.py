N = int(input())
sizes = list(map(int, input().split()))
T, P = map(int, input().split())

Tshirts = 0
for i in range(6):
    Tshirts += (sizes[i] // T) + (sizes[i] % T != 0)
print(Tshirts)
print(N // P, N % P)