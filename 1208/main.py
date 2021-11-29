def main():
    N = int(input())

    teams = []
    for i in range(N):
        teams.append( input().split() )

    participants = set()
    for team in teams:
        for p in team:
            participants.add(p)

    participants_list = list(participants)

    teams_code = []
    for team in teams:
        code = 0
        for p in team:
            code = code | (1 << participants_list.index(p))
        teams_code.append(code)

    result = 0

    while len(teams_code):
        result += 1

        team = teams_code[0]
        team_sum = len(teams_code)

        for x in teams_code:
            sum = 0
            for y in teams_code:
                if x & y:
                    sum += 1
            if team_sum > sum:
                team_sum = sum
                team = x

        teams_code = [x for x in teams_code if ( x & team ) == 0]

    print(result)

if __name__ == '__main__':
    main()
