def sum_digits(n):
    r = 0
    while n:
        r, n = r + n % 10, n // 10
    return r

def main():
    n = int(input())

    result = []
    while n:
        result.append(n)
        n -= sum_digits(n)

    print(len(result))
    print(*result)

if __name__ == '__main__':
    main()
