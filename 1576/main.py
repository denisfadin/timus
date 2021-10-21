def main():
    N1, C1 = map(int, input().split())
    N2, T, C2 = map(int, input().split())
    N3 = int(input())

    K = int(input())
    minutes = 0
    for i in range(K):
        MM, SS = map(int, input().split(':'))
        if MM == 0 and SS < 7:
            continue
        minutes += MM
        if SS > 0:
            minutes += 1

    print('Basic:     {}'.format(N1+C1*minutes))
    print('Combined:  {}'.format(N2+((minutes-T)*C2 if minutes > T else 0)))
    print('Unlimited: {}'.format(N3))

if __name__ == '__main__':
    main()
