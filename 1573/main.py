import sys

def main():
    B, R, Y = map(int, input().split())
    K = int(input())
    result = 1
    for i in range(K):
        str = input()
        if str == 'Blue':
            result *= B
        elif str == 'Red':
            result *= R
        else: # 'Yellow'
            result *= Y
    print(result)

if __name__ == '__main__':
    main()
