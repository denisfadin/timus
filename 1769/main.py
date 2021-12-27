def main():
    line = input()
    MAX=1000000
    cache = [False]*MAX

    for i in range(len(line)):
        if line[i]=='0':
            continue
        for j in range(1,7):
            if i+j>len(line):
                break
            cache[int(line[i:i+j])]=True

    for i in range(1, MAX):
        if not cache[i]:
            print(i)
            return

if __name__ == '__main__':
    main()
