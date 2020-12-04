import sys

# используем аналог алгоритма вычисления чисел фибоначчи черем степень матрицы
#
# в том числе используем быстрый алгоритм возведение в степень через разложение
# степени на сумму степеней двойки

def multiply(m1, m2):
    return [
        [
            m1[0][0] * m2[0][0] + m1[0][1] * m2[1][0],
            m1[0][0] * m2[0][1] + m1[0][1] * m2[1][1]
        ],
        [
            m1[1][0] * m2[0][0] + m1[1][1] * m2[1][0],
            m1[1][0] * m2[0][1] + m1[1][1] * m2[1][1]
        ]
    ]

def main():
    N = int(input())
    K = int(input())

    result = [[1, 0], [0, 1]]
    pow = [[K-1, K-1], [1, 0]]

    for i in range(11): # 2^10=2048
        if N & (1 << i):
            result = multiply(result, pow)
        pow = multiply(pow, pow)

    print(result[0][0])

if __name__ == "__main__":
    main()

# Прыдудущий вариант рещения через ДП
#
# N = int(input())
# K = int(input())
#
# cache1 = K-1
# cache2 = (K-1)*K
#
# for i in range(3, N+1):
#     tmp = (K-1)*(cache2 + cache1)
#     cache1 = cache2
#     cache2 = tmp
#
# print(cache2)
