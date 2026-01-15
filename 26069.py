n = int(input())

people = set()

for i in range(n):
    person1, person2 = input().split()
    
    if person1 == "ChongChong":
        people.add(person2)
    elif person2 == "ChongChong":
        people.add(person1)
    elif person1 in people:
        people.add(person2)
    elif person2 in people:
        people.add(person1)
    
print(len(people) + 1)