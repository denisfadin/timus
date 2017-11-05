#include <cstdint>
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
   int16_t K;
   std::cin >> K;

   std::vector< int16_t > v( K );
   for( int16_t i = 0; i < K; ++i )
      std::cin >> v[i];

   std::sort( v.begin(), v.end() );

   int16_t result = 0;
   for( int16_t i = K/2; i >= 0; --i )
      result += v[i]/2+1;

   std::cout << result << std::endl;

   return 0;
}