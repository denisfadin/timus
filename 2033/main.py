import sys
import functools

def main():
    data = []
    for i in range(6):
        name = input()
        device = input()
        price = int(input())

        val = ([v for v in data if v[0] == device][:1] or [None])[0]
        if val:
            val[1] = val[1] + 1
            val[2] = min(val[2], price)
        else:
            data.append([device, 1, price])

    def compare(item1, item2):
        if item1[1] < item2[1]:
            return -1
        elif item1[1] > item2[1]:
            return 1
        elif item1[2] > item2[2]:
            return -1
        elif item1[2] < item2[2]:
            return 1
        else:
            return 0

    data = sorted(data, key=functools.cmp_to_key(compare))

    print(data[-1][0])

if __name__ == '__main__':
    main()
