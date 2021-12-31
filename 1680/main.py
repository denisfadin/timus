def main():
    year, n, q = map(int, input().split())
    final_universities = set()
    for i in range(n):
        command = input()

        uni = command
        pos = uni.find('#')
        if pos != -1:
            uni = uni[:pos-1]

        if uni in final_universities:
            continue

        if len(final_universities) == q:
            print(command)
            return

        final_universities.add(uni)

if __name__ == '__main__':
    main()
