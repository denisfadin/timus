def print_result(contests):
    print('+------------------------------+--------+-------------+')
    print('|Contest name                  |Date    |ABCDEFGHIJKLM|')
    print('+------------------------------+--------+-------------+')
    for contest in contests:
        print('|{0: <30}|{1: <8}|{2: <13}|'.format(contest['name'], contest['date'], contest['tasks']))
        print('+------------------------------+--------+-------------+')

def read_contests():
    contests = []

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
        contests.append({'name': name, 'date': date, 'tasks': ''.join(tasks)})

    return contests

def main():
    print_result(read_contests())

if __name__ == '__main__':
    main()
