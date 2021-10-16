def main():
    N = int(input())
    task_names = []
    for i in range(0, N):
        task_names.append(input().split())
        task_names[-1].sort()
    task_order = list(map(int, input().split()))
    ordered_task_names = []
    for i in task_order:
        ordered_task_names.append(task_names[i-1])
    result = [ordered_task_names[0][0]]
    for i in range(1, N):
        for name in ordered_task_names[i]:
            if name > result[-1]:
                result.append(name)
                break
        if len(result) != i+1:
            print('IMPOSSIBLE')
            return

    for name in result:
        print(name)

if __name__ == '__main__':
    main()
