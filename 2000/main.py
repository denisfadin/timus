import math

def main():
    N = int(input())

    data = list(map(int, input().split()))

    pos1, pos2 = map( int, input().split() )
    pos1 -= 1
    pos2 -= 1

    if pos1 == pos2:
        if pos1 == 0 or pos1 == N-1:
            print( sum(data), 0 )
        else:
            sum1 = sum(data[:pos1])
            sum2 = sum(data[pos1+1:])
            print(data[pos1]+max(sum1, sum2), min(sum1, sum2))
    elif pos1 < pos2:
        posm = int(( pos1 + pos2 ) / 2)
        sum1 = sum(data[:posm+1])
        sum2 = sum(data[posm+1:])
        print( sum1, sum2 )
    else:
        posm = int(math.ceil(( pos1 + pos2 ) / 2))
        sum1 = sum(data[posm:])
        sum2 = sum(data[:posm])
        print( sum1, sum2 )

if __name__ == '__main__':
    main()
