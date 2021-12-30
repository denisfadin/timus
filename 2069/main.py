def read_lines(k):
    f = int(input())
    m = 0
    for i in range(k-2):
        m = max(m, int(input()))
    l = int(input())
    return f, m, l

def main():
    N, M = map(int, input().split())

    vf, vm, vl = read_lines(N)
    hf, hm, hl = read_lines(M)

    r1 = min(hf, vl)
    r2 = min(vf, hl)
    r3 = min(vf, hm, vl)
    r4 = min(hf, vm, hl)

    print(max(r1, r2, r3, r4))

if __name__ == '__main__':
    main()
