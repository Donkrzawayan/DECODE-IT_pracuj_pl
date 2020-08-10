n = int(input())
members = []
for i in range(n):
    line = input()
    line = line.split()
    members.append((line[0], int(line[1])))

m = int(input())
friendship = []
for i in range(m):
    line = input()
    line = line.split()
    friendship.append((line[0], line[1]))

print(n)
w_sum = 0
for member in members:
    print(member[0])
    w_sum += member[1]

print(w_sum)
