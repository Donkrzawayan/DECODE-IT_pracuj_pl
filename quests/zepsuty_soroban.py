import itertools


def add_value(lista, value):
    if value in lista:
        pass
    else:
        lista.append(value)


def add_down_value(lista, value):
    value = sorted(value)
    if value in lista:
        pass
    else:
        add_value(lista, value)


line = input()
line = line.split()
r = int(line[0])
s = int(line[1])

upper_variation_with_repetitions = 2 ** r

# generate permutations
down_permutation_with_repetitions = []

word = ''
if s > 4:
    word = '4' * (s // 4)
if s % 4 != 0:
    word += str(s % 4)
if len(word) < r:
    word += '0' * (r - len(word))

for i in itertools.permutations(word, r):
    add_value(down_permutation_with_repetitions, i)

last_index = -1
while '0' == word[last_index] and word[0] != '0':
    new_first_number = str(int(word[0]) - 1)
    if last_index >= -1:
        word = new_first_number + word[1:last_index] + '1'
    else:
        word = new_first_number + word[1:last_index] + '1' + word[last_index + 1:]
    last_index -= 1

    for i in itertools.permutations(word, r):
        add_down_value(down_permutation_with_repetitions, i)

# count permutations
answer = 0
for i in down_permutation_with_repetitions:
    options = 1
    for j in i:
        options *= int(j) + 1
    if options > answer:
        answer = options

print(answer * upper_variation_with_repetitions)
