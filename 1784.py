N, M = map(int, input().split())

listen = set()
people = []

for i in range(N):
    listen.add(input().strip())

for i in range(M):
    song = input().strip()
    if song in listen:
        people.append(song)

print(len(people))
people.sort()
for person in people:
    print(person)
