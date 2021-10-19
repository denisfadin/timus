def main():
   n, m = map(int, input().split())
   n *= 3
   sum = 0
   for i in range(m):
      sum += int(input())
      if sum > n:
         print('Free after {} times.'.format(i+1))
         return
   print('Team.GOV!')

if __name__ == '__main__':
   main()
