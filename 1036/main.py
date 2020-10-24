import sys

N, S = map(int, input().split())

cache = {}
def Do(sum, length):
    if length == 1:
        if sum >= 0 and sum <= 9:
            return 1;
        return 0;

    cache_key = (sum << 16) + length
    if cache_key in cache:
        return cache[ cache_key ]

    result = 0
    for i in range(0, 10):
        if sum >= i:
            result += Do(sum - i, length - 1)

    cache[ cache_key ] = result

    return result

result = 0
if S % 2 == 0:
    result = Do(S // 2, N)

print(result * result)
