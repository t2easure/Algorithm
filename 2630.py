blue = 0
white = 0

N = int(input())

def all_same(paper, n):
    standard = paper[0][0]
    for i in range(n):
        for j in range(n):
            if paper[i][j] != standard:
                return False
    return True

def split_paper(paper, n):
    global blue, white
    if all_same(paper, n):
        if paper[0][0] == 1:
            blue += 1
        else: white += 1
        return
    
    leftup = [ i[:n//2]for i in paper[:n//2] ]
    rightup = [ i[n//2:] for i in paper[:n//2] ]
    leftdown = [ i[:n//2] for i in paper[n//2:] ]
    rightdown = [ i[n//2:] for i in paper[n//2:] ]

    result = [leftup, rightup, leftdown, rightdown]
    for section in result:
        split_paper(section, n//2)

paper = []
for i in range(N):
    temp = list(map(int, input().split()))
    paper.append(temp)

if all_same(paper, N):
    if paper[0][0] == 1:
        blue = 1
        white = 0
    else:
        white = 1
        blue = 0
else:
    split_paper(paper, N)

print(white)
print(blue)