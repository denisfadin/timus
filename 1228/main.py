import sys

def main():
    N, S = map(int, input().split())

    data = [S]
    for i in range(N):
        data.append(int(input()))

    result = []
    for i in range(N,0,-1):
        result.append(int(data[i-1]/data[i])-1)

    for r in reversed(result):
        print(r)

if __name__ == '__main__':
    main()
