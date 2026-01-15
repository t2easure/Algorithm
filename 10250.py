T = int(input())

for _ in range(T):
    H, W, N = map(int, input().split())
    
    # 열 계산: (N-1) // H + 1
    column = (N - 1) // H + 1
    
    # 층 계산: (N-1) % H + 1
    floor = (N - 1) % H + 1
    
    # 방 번호 생성: YYXX 또는 YXX 형식
    # YY는 층수를 나타내며, XX는 열 번호를 나타냄
    room_number = f"{floor}{column:02d}"
    
    print(room_number)
