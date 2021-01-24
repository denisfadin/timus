import sys

def main():
    N = int(input())

    if N <= 2:
        print(N)
        return

    data = dict()
    data[1] = 1
    data[2] = 2

    num = 1
    for i in range(2, 31):
        num *= 10
        new_data = dict()

        for j in range(2):
            tmp_num = num << j
            rem = tmp_num % N

            for key, value in data.items():
                v = tmp_num + value
                k = key + rem

                if k == N:
                    print(v)
                    return

                if k > N:
                    k -= N

                if k in new_data and new_data[k] < v:
                    continue

                new_data[k] = v

        data = new_data

    print('Impossible')

if __name__ == '__main__':
    main()
