import sys

def main():
    N = int(input())
    max_hungry = 2
    min_satisfied = 10
    for i in range(N):
        value, result = [int(i) if i.isdigit() else i for i in input().split()]
        if result == 'hungry':
            if max_hungry < value:
                max_hungry = value
        else: # satisfied
            if min_satisfied > value:
                min_satisfied = value

    if min_satisfied > max_hungry:
        print(min_satisfied)
    else:
        print('Inconsistent')

if __name__ == '__main__':
    main()
