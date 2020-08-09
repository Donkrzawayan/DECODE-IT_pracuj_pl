def warm_up():
    t = input()

    for i in range(int(t)):
        line = input()
        line = line.split()
        c = int(line[0])
        k = int(line[1])
        w = int(line[2])
        if (c * w) <= k:
            print("yes")
        else:
            print("no")


warm_up()
