import sys

def main():
    N = int(input())

    data = [0]
    for i in range(N):
        K = int(input())
        tmp_data = [sys.maxsize]*K
        for j in range(K):
            e = list(map(int, input().split()))
            l = 0
            while e[l]:
                idx = e[l]-1
                val = e[l+1]
                if data[idx] != sys.maxsize:
                    tmp_data[j] = min(tmp_data[j], data[idx]+val)
                l += 2
        if i < N-1:
            input()
        data = tmp_data

    print(min(data))

if __name__ == '__main__':
    main()
