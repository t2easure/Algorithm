n = int(input())

words = set()
num = 0

for i in range(n):
    StrWord = input()
    if StrWord == "ENTER":
        words = set()
    elif StrWord not in words:
        words.add(StrWord)
        num += 1

print(num)