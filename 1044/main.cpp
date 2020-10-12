#include <iostream>
#include <cstdint>

uint64_t D( uint32_t n, uint32_t k )
{
   if( n == 0 )
      return k == 0 ? 1 : 0;

   uint64_t result = 0;
   for( uint32_t j = 0; j <= 9; ++j )
      result += D( n - 1, k - j );

   return result;
}

int main()
{
   uint32_t N;
   std::cin >> N;

   std::cout << D( N, 9 * ( N >> 1 ) ) << std::endl;

   return 0;
}
