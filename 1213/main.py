def main():
    modules = set({input()})
    while True:
        line = input()
        if line == '#':
            break
        modules.update(line.split('-'))
    print(len(modules)-1)

if __name__ == '__main__':
    main()
