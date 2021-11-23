def main():
    n = int(input())
    points = list()
    for i in range(n):
        points.append(tuple(map(int, input().split())))
    sum = 0
    for i in range(n):
        for j in range(i+1,n):
            sum += abs(points[i][0]-points[j][0])
            sum += abs(points[i][1]-points[j][1])
    print(int((2*sum)/(n*(n-1))))

if __name__ == '__main__':
    main()
