import sys

def main():
    X, Y, C = map(int, input().split())

    if X + Y < C:
        print('Impossible')
    else:
        a = min(X, C)
        b = C - a
        print(a, b)

if __name__ == "__main__":
    main()
