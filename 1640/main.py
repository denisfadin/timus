import math

def main():
    N = int(input())
    result = 0
    for i in range(N):
        x, y = map(int, input().split())
        result = max(result, math.sqrt(x*x + y*y))
    print(0, 0, result)

if __name__ == '__main__':
    main()
