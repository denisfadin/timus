import sys

def main():
    sum = 0
    base = 2
    while True:
        num = ord(sys.stdin.read(1))
        if num == 10: # '\n'
            break
        if num >= 65: # alpha
            num -= 55 # 65 - 10
        else:
            num -= 48 # digit
        sum += num
        base = max(base, num+1)
            
    for i in range(base, 37):
        if sum % (i - 1) == 0:
            print(i)
            return
    print('No solution.')

if __name__ == '__main__':
    main()
