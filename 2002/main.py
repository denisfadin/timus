import sys

def main():
    N = int(input())

    users = dict()
    sessions = set()

    for i in range(N):
        req = input().split(' ')
        command, username = req[:2]

        if command == 'register':
            if username in users:
                print('fail: user already exists')
            else:
                users[username] = req[2]
                print('success: new user added')

        elif command == 'login':
            if username not in users:
                print('fail: no such user')
            elif req[2] != users[username]:
                print('fail: incorrect password')
            elif username in sessions:
                print('fail: already logged in')
            else:
                sessions.add(username)
                print('success: user logged in')

        else: # 'logout'
            if username not in users:
                print('fail: no such user')
            elif username not in sessions:
                print('fail: already logged out')
            else:
                sessions.discard(username)
                print('success: user logged out')

if __name__ == "__main__":
    main()
