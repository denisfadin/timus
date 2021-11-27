from sys import stdin

def main():
    N = int(input())

    reletions = set()
    for line in stdin:
        if line[0] == 'B':
            break
        a, b = map(int, line.split())
        reletions.add((a, b))

    result = [True] * (N+1)
    for line in stdin:
        a = int(line)
        # спускаемся вниз
        to_process = [a]
        while len(to_process) > 0:
            x = to_process.pop()
            result[ x ] = False
            for i in range(1, N+1):
                if (x, i) in reletions:
                    to_process.append(i)
        # поднимаемся вверх
        to_process = [a]
        while len(to_process) > 0:
            x = to_process.pop()
            result[ x ] = False
            for i in range(1, N+1):
                if (i, x) in reletions:
                    to_process.append(i)

    result_list = []
    for i in range(1, N+1):
        if result[i]:
            result_list.append(i)
    if len(result_list) > 0:
        print(' '.join(str(r) for r in result_list))
    else:
        print(0)

if __name__ == '__main__':
    main()
