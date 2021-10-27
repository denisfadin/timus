def main():
    N = int(input())
    D, A = map(int, input().split())
    data = list(range(N))
    to_delete = set()
    for i in range(N):
        line = input()
        for j in range(i+1, N):
            if line[j]=='0':
                continue
            if data[i]==data[j]:
                to_delete.add((i, j))
                continue
            di = data[i]
            dj = data[j]
            for k in range(N):
                if data[k]==dj:
                    data[k] = di
    to_add = set()
    d0 = data[0]
    for i in range(1, N):
        if d0 != data[i]:
            to_add.add((0, i))
            di = data[i]
            for k in range(i, N):
                if data[k] == di:
                    data[k] = d0

    print(len(to_delete)*D+len(to_add)*A)
    for i in range(N):
        line = []
        for j in range(N):
            key = (min(i,j), max(i,j))
            if key in to_delete:
                line.append('d')
            elif key in to_add:
                line.append('a')
            else:
                line.append('0')
        print(''.join(line))

if __name__ == '__main__':
    main()
