def main():
    N = int(input())
    if N < 5:
        print(N)
    elif N % 3 == 1:
        print(4*(3**int((N-4)/3)))
    else:
        if N % 3 != 0:
            print((N%3)*(3**int((N-N%3)/3)))
        else:
            print(3**int((N-N%3)/3))

if __name__ == '__main__':
    main()
