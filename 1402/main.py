def main():
    N = int(input())
    result = 0
    for i in range(2, N+1):
        i_result = 1
        for j in range(N-i+1, N+1):
            i_result *= j
        result += i_result 
    print(result)

if __name__ == '__main__':
    main()
