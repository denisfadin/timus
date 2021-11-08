import sys

def main():
    N, M = map(int, input().split())
    UP_ROAD = [[] for x in range(N+1)]
    DOWN_ROAD = [[] for x in range(N+1)]
    for i in range(M):
        x, y = map(int, input().split())
        UP_ROAD[x].append(y)
        DOWN_ROAD[y].append(x)
    A, B = map(int, input().split())
    checked = [False]*(N+1)
    to_process = [A]
    UP = [sys.maxsize]*(N+1)
    UP[A]=0
    DOWN = [sys.maxsize]*(N+1)
    DOWN[A]=0
    while len(to_process):
        p = to_process.pop(0)
        if checked[p]:
            continue
        checked[p]=True
        for y in UP_ROAD[p]:
            if not checked[y]:
                to_process.append(y)
            UP[y] = min(UP[y], UP[p])
            if DOWN[p] is not sys.maxsize:
                UP[y] = min(UP[y], DOWN[p]+1)
        for y in DOWN_ROAD[p]:
            if not checked[y]:
                to_process.append(y)
            DOWN[y] = min(DOWN[y], DOWN[p])
            if UP[p] is not sys.maxsize:
                DOWN[y] = min(DOWN[y], UP[p]+1)

    print(min(UP[B], DOWN[B]))

if __name__ == '__main__':
    main()
