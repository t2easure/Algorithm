T = int(input())

for i in range(T):
    N = int(input())
    outfits = {}
    for j in range(N):
        outfit, types = map(str, input().split())
        if types in outfits.keys():
            outfits[types].append(outfit)
        else:
            outfits[types] = [outfit]
    

    num = 1
    for j in outfits.keys():
        num *= len(outfits[j]) + 1
    
    print(num - 1)