#include <cstdint>
#include <cstdio>
#include <cinttypes>

int main()
{
    uint32_t N;
    std::scanf( "%" SCNu32, &N );

    uint32_t result = 0;
    uint32_t sum = 0;

    while( true )
    {
        char sym = std::getchar();
        if( sym == '>' )
            ++sum;
        else if( sym == '<' )
            result += sum;
        else if( sym == EOF )
            break;
    }

    std::printf( "%" PRIu32 "\n", result );

    return 0;
}
