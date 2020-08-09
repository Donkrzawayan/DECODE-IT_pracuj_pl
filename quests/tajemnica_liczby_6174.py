t = int(input())

for i in range(t):
    a = input()
    count = 0
    while True:
        if a == "6174":
            print(count)
            break

        count += 1
        asc = int(''.join(sorted(a, reverse=False)))
        dsc = int(''.join(sorted(a, reverse=True)))
        a = dsc - asc
        if a < 1000:
            if a < 100:
                if a < 10:
                    if a == 0:
                        print("-1")
                        break
                    else:
                        a = "000" + str(a)
                else:
                    a = "00" + str(a)
            else:
                a = "0" + str(a)
        else:
            a = str(a)
