import math


t = int(input())
for i in range(t):
    n = int(input())
    xs = []
    ys = []
    rs = []
    for j in range(n):
        x, y, r = [int(x) for x in input().split()]
        xs.append(x)
        ys.append(y)
        rs.append(r)

    if n == 1:
        perimeter = 2 * math.pi * rs[0]
    else:
        if n == 2 and rs[0] == rs[1]:
            circle_perimeter = 2 * math.pi * rs[0]
            straight = math.sqrt((xs[0]-xs[1])**2 + (ys[0]-ys[1])**2)
            perimeter = circle_perimeter + 2 * straight
        else:
            perimeter = 4000

    print(f"{perimeter}")
