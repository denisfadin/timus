def main():
    l, k, h = map(int, input().split())
    print("%.5f" % (int(l/k)*h), "%.5f" % ((int(l/k)+(1 if l%k else 0))*h))

if __name__ == '__main__':
    main()
