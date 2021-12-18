def process_list(l):
    l.sort()
    result = 0
    p = 0
    for i in range(1, len(l)):
        p = p + (l[i]-l[i-1])*i*2
        result += p
    return result

def main():
    n = int(input())

    x_list = list()
    y_list = list()
    for i in range(n):
        x, y = map(int, input().split())
        x_list.append( x )
        y_list.append( y )

    sum = process_list(x_list)+process_list(y_list)
    print(int(sum/(n*(n-1))))

if __name__ == '__main__':
    main()
