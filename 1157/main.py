import math

def main():
    MAX = 10000
    M, N, K = map(int, input().split())
    for i in range(1, MAX-K+1):
        divisiors_count = 1
        for j in range(2, int(math.sqrt(i))+1):
            if i % j == 0:
                divisiors_count += 1
        if divisiors_count == M:
            divisiors_count2 = 1
            for j in range(2, int(math.sqrt(i+K))+1):
                if (i+K) % j == 0:
                    divisiors_count2 += 1
            if divisiors_count2 == N:
                print(i+K)
                return
    print(0)

if __name__ == '__main__':
    main()
