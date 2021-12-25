def main():
    N = int(input())
    data = [0]*(N*N)
    for i in range(N*N):
        data[i] = int(input())
    data.sort(reverse=True)

    mid = int(N/2)
    sorted_data = []
    for i in range(N):
        sorted_data.append([0]*N)
    data_pos = 0
    for i in range(mid+1):
        for j in range(mid+1):
            sorted_data[mid-j][mid-i] = data[data_pos]
            data_pos += 1
            if j == 0:
                continue
            sorted_data[mid+j][mid-i] = data[data_pos]
            data_pos += 1
        if i == 0:
            continue
        for j in range(mid+1):
            sorted_data[mid-j][mid+i] = data[data_pos]
            data_pos += 1
            if j == 0:
                continue
            sorted_data[mid+j][mid+i] = data[data_pos]
            data_pos += 1

    for i in range(N):
        print(' '.join(str(x) for x in sorted_data[i]))

if __name__ == '__main__':
    main()
