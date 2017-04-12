import sys
import random
import string

def Number2Word( number ):
    d = {
        '1': 'i',
        '2': 'a',
        '3': 'd',
        '4': 'g',
        '5': 'k',
        '6': 'm',
        '7': 'p',
        '8': 't',
        '9': 'w',
        '0': 'o'
        }
    return ''.join( d[x] for x in number )

def main( argv ):
    with open( argv[0], 'w' ) as file:
        N = int(argv[1])
        number = ''.join(random.choice(string.digits) for _ in range(N))
        file.write( "%s\n" % number )

        K = int(argv[2])
        file.write( "%d\n" % (K+1) )
        randoms_arr = random.sample(range(1,N-1),K)
        randoms_arr.sort()
        randoms_arr.append( N )

        idx = 0
        for r in randoms_arr:
            file.write( "%s\n" % Number2Word(number[idx:r]) )
            idx = r

        file.write( "%s\n" % "-1" )

if __name__ == "__main__":
    main(sys.argv[1:])
