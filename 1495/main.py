import sys

def calc(n, rem, data, i=0):
    rem1 = rem - data[i][1]
    rem2 = rem - data[i][2]

    if rem1 == 0:
        return '1'
    if rem2 == 0:
        return '2'

    if i+1 < len(data):
        if rem1 < 0:
            rem1 += n
        res1 = calc(n, rem1, data, i+1)
        if res1:
            return res1 + '1'

        if rem2 < 0:
            rem2 += n
        res2 = calc(n, rem2, data, i+1)
        if res2:
            return res2 + '2'

    return None

def main():
    N = int(input())

    if N <= 2:
        print(N)
        return

    data = list()
    num = 1
    for i in range(30):
        d = dict()
        d[1] = num % N
        d[2] = (num << 1) % N
        data.append(d)
        num *= 10

    result = calc(N, N, data)
    if result:
        print(result)
    else:
        print('Impossible')

if __name__ == '__main__':
    main()
