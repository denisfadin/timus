def main():
    south = input()
    north = input()

    result = 0

    i = 0
    j = 0
    while True:
        if i == len(south):
            result += len(north)-j
            break
        elif j == len(north):
            result += len(south)-i
            break
        else:
            if south[i] == 'L' and north[j] != 'L':
                result += 1
                j += 1
            elif north[j] == 'L' and south[i] != 'L':
                result += 1
                i += 1
            else:
                result += 1
                i += 1
                j += 1

    print(result)

if __name__ == '__main__':
    main()
