import sys

N = int(input())
K = int(input())

cache1 = K-1
cache2 = (K-1)*K

for i in range(3, N+1):
    tmp = (K-1)*(cache2 + cache1)
    cache1 = cache2
    cache2 = tmp

print(cache2)
