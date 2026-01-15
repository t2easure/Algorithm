T = int(input())

for i in range(T):
    n = list(map(str, input().split()))
    number = float(n[0])
    for j in range(1, len(n)):
        if n[j] == "@":
            number *= 3
        elif n[j] == "%":
            number += 5
        elif n[j] == "#":
            number -= 7
    print(f"{number:.2f}")