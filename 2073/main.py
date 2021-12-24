def main():
    print('+------------------------------+--------+-------------+')
    print('|Contest name                  |Date    |ABCDEFGHIJKLM|')
    print('+------------------------------+--------+-------------+')

    N = int(input())
    for contest_id in range(N):
        name = input()
        date = input()

        p, s = map(int, input().split())
        tasks = ['.']*p
        for i in range(s):
            line = input()
            task_id = ord(line[0])-ord('A')
            if tasks[task_id] == 'o':
                continue
            if line[2:] == 'Accepted':
                tasks[task_id] = 'o'
            else:
                tasks[task_id] = 'x'

        print('|{0: <30}|{1: <8}|{2: <13}|'.format(name, date, ''.join(tasks)))
        print('+------------------------------+--------+-------------+')

if __name__ == '__main__':
    main()
