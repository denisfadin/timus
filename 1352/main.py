import sys

def main():
    data = {
        1: 2,
        2: 3,
        3: 5,
        4: 7,
        5: 13,
        6: 17,
        7: 19,
        8: 31,
        9: 61,
        10: 89,
        11: 107,
        12: 127,
        13: 521,
        14: 607,
        15: 1279,
        16: 2203,
        17: 2281,
        18: 3217,
        19: 4253,
        20: 4423,
        21: 9689,
        22: 9941,
        23: 11213,
        24: 19937,
        25: 21701,
        26: 23209,
        27: 44497,
        28: 86243,
        29: 110503,
        30: 132049,
        31: 216091,
        32: 756839,
        33: 859433,
        34: 1257787,
        35: 1398269,
        36: 2976221,
        37: 3021377,
        38: 6972593
    }

    T = int(input())
    for i in range(0, T):
        N = int(input())
        print(data[N])

if __name__ == '__main__':
    main()