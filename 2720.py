T = int(input())


for i in range(T):
    Q = 0
    D = 0
    N = 0
    P = 0
    
    money = int(input())
    
    while money >= 25:
        money -= 25
        Q += 1
    
    while money >= 10:
        money -= 10
        D += 1
    
    while money >= 5:
        money -= 5
        N += 1
    
    while money > 0:
        money -= 1
        P += 1
    
    print(Q, D, N, P)
        
    