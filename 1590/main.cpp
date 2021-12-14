#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::string str;
    std::getline( std::cin, str );
    
    std::vector< uint32_t > pi(str.size(), 0);

    uint32_t result = 1;
    for( uint32_t pos = 1; pos < str.size(); ++pos )
    {
        uint32_t pi_max = 0;
        for( uint32_t i = 1; i <= pos; ++i )
        {
            uint32_t j = pi[i-1];
            while( j > 0 && str[pos-i] != str[pos-j] )
                j = pi[j-1];
            if( str[pos-i] == str[pos-j] )
                ++j;
            pi[i] = j;
            pi_max = std::max( pi_max, pi[i] );
        }
        result += pos + 1 - pi_max;
    }

    std::cout << result << std::endl;
    
    return 0;
}
