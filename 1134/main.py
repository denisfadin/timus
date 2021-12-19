def check(data):
    for i in range(len(data)-1):
        if data[i] > 1:
            return False
        elif data[i] == 0:
            if data[i+1] > 0:
                data[i+1] -= 1
                data[i] += 1
    return data[-1]+data[-2] <= 1

def main():
    N, M = map(int, input().split())

    data = [0]*(N + 1)
    for x in map(int, input().split()):
        data[x] += 1

    if check(data)==True:
        print('YES')
    else:
        print('NO')

if __name__ == '__main__':
    main()
