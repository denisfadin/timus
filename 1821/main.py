def time_to_int(time_str):
    mm, ss = time_str.split(':')
    ss, d = ss.split('.')
    return int(d) + int(ss)*10 + int(mm)*600

def main():
    N = int(input())
    data = []
    for i in range(N):
        name, time_str = input().split()
        time = time_to_int(time_str)
        data.append((name, time, time+i*300))
    data.sort(key=lambda tup: tup[2])

    j = 1
    while j < len(data):
        if data[j-1][1] > data[j][1]:
            j += 1
        else:
            del data[j]

    data.sort(key=lambda tup: tup[0])

    print(len(data))
    for d in data:
        print(d[0])

if __name__ == '__main__':
    main()
