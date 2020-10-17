#include <cstdint>
#include <iostream>
#include <vector>

int main()
{
   uint16_t N;
   std::cin >> N;

   std::vector< uint16_t > image( N*N );
   for( uint16_t i = 0; i < N; ++i )
      for( uint16_t j = 0; j < N; ++j )
         std::cin >> image[ i*N + j ];

   for( uint16_t k = 0; k < N; ++k )
      for( uint16_t i = 0, j = 0; i <= k; ++i, ++j )
         std::cout << image[ (k-i)*N + j ] << " ";

   for( uint16_t k = 1; k < N; ++k )
      for( uint16_t i = N-1, j = k; j < N; --i, ++j )
         std::cout << image[ i*N + j ] << " ";

   std::cout << std::endl;

   return 0;
}
