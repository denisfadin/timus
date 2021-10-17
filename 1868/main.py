def main():
    winners = dict()
    for medal in ['gold', 'silver', 'bronze']:
        for i in range(4):
            winners[input()]=medal

    result_max_sum = 0
    result_cnt = 0
    for i in range(int(input())):
        sum = 0
        for j in range(int(input())):
            name, medal = input().split(' : ')
            if name not in winners.keys():
               continue
            if winners[name] != medal:
               continue
            sum+=1
        if sum > result_max_sum:
            result_max_sum = sum
            result_cnt = 1
        elif sum == result_max_sum:
            result_cnt += 1

    print(5*result_cnt)

if __name__ == '__main__':
   main()
