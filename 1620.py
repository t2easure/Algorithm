import sys

N, M = map(int, sys.stdin.readline().split())

pokemon_dict = {}
pokemon_list = [None]

for i in range(1, N + 1):
    name = sys.stdin.readline().rstrip()
    pokemon_dict[name] = i
    pokemon_list.append(name)

answers = []

for i in range(1, M + 1):
    question = sys.stdin.readline().rstrip()
    
    try:
        question_int = int(question)
        answers.append(pokemon_list[question_int])
    except ValueError:
        answers.append(str(pokemon_dict[question]))

sys.stdout.write('\n'.join(answers))
