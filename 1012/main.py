import sys

N = int(input()) 
K = int(input())

cache = {}
cache[1] = K-1
cache[2] = (K-1)*K

for i in range(3, N+1):
    cache[i] = (K-1)*(cache[i-1] + cache[i-2])

print(cache[N])
