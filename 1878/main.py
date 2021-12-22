def main():
    c = list()
    for i in range(4):
        c.append(list(map(int, input().split())))

    r = [0]*5
    for x in [c[2][0], c[2][1], c[3][0], c[3][1], c[0][2], c[0][3], c[1][2], c[1][3]]:
        r[x] += 1

    for x in [c[2][2], c[2][3], c[3][2], c[3][3]]:
        r[x] += 2

    print(min(r[1:]))

if __name__ == '__main__':
    main()
