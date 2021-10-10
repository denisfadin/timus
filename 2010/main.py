# Король
def getKing(x, y, n):
    result = 0
    if x > 1:
        result += 1
        if y > 1:
            result += 1
        if y < n:
            result += 1
    if x < n:
        result += 1
        if y > 1:
            result += 1
        if y < n:
            result += 1
    if y > 1:
        result += 1
    if y < n:
        result += 1
    return result

# Конь
def getKnight(x, y, n):
    result = 0
    if x > 2 and y > 1:
        result += 1
    if x > 2 and y < n:
        result += 1
    if x < n-1 and y > 1:
        result += 1
    if x < n-1 and y < n:
        result += 1
    
    if x > 1 and y > 2:
        result += 1
    if x > 1 and y < n-1:
        result += 1
    if x < n and y > 2:
        result += 1
    if x < n and y < n-1:
        result += 1
    return result

# Слон
def getBishop(x, y, n):
    result = 0
    result += min(x-1, y-1)
    result += min(n-x, y-1)
    result += min(x-1, n-y)
    result += min(n-x, n-y)
    return result

# Ладья
def getRook(x, y, n):
    return n * 2 - 2

# Ферзь
def getQueen(x, y, n):
    return getBishop(x, y, n) + getRook(x, y, n)

def main():
    n = int(input())
    x, y = map(int, input().split())
    
    print('King: {}'.format(getKing(x, y, n)))
    print('Knight: {}'.format(getKnight(x, y, n)))
    print('Bishop: {}'.format(getBishop(x, y, n)))
    print('Rook: {}'.format(getRook(x, y, n)))
    print('Queen: {}'.format(getQueen(x, y, n)))

if __name__ == '__main__':
    main()
