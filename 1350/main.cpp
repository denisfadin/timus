def main():
    N = int(input())
    products = set()
    for i in range(N):
        products.add(input())
    K = int(input())

    def read_list():
        result = set()
        for i in range(int(input())):
            result.add(input())
        return result

    products -= read_list()

    data = []
    for i in range(K):
        data.append(read_list())

    M = int(input())

    for i in range(K):
        l = len(products.intersection(data[i]))
        if l == 0 or M == 0:
            print('YES')
        elif len(products)-l >= M:
            print('MAYBE')
        else:
            print('NO')

if __name__ == '__main__':
    main()
