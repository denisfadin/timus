import sys

# используем аналог алгоритма вычисления чисел фибоначчи черем степень матрицы
#
# в том числе используем быстрый алгоритм возведение в степень через разложение
# степени на сумму степеней двойки

def multiply(m1, m2, mod):
    return [
        [
            ( m1[0][0] * m2[0][0] + m1[0][1] * m2[1][0] ) % mod,
            ( m1[0][0] * m2[0][1] + m1[0][1] * m2[1][1] ) % mod
        ],
        [
            ( m1[1][0] * m2[0][0] + m1[1][1] * m2[1][0] ) % mod,
            ( m1[1][0] * m2[0][1] + m1[1][1] * m2[1][1] ) % mod
        ]
    ]

def main():
    N = int(input())
    K = int(input())
    M = int(input())

    result = [[1, 0], [0, 1]]
    pow = [[K-1, K-1], [1, 0]]

    for i in range(63):
        if N & (1 << i):
            result = multiply(result, pow, M)
        pow = multiply(pow, pow, M)

    print(result[0][0])

if __name__ == "__main__":
    main()
