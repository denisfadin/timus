#include <cstdint>
#include <iostream>
#include <vector>

int main()
{
   uint32_t N, K;
   std::cin >> N >> K;

   std::vector< uint32_t > cache( N + 1, 0 );

   // cache[ j ] - сколько последовательностей длины j, начинающихся на 0
   // cache[ j ] - сколько последовательностей длины j+1, начинающихся на 1

   cache[ 0 ] = cache[ 1 ] = 1;
   for( uint32_t i = 2; i <= N; ++i )
      cache[ i ] = cache[ i - 1 ] + cache[ i - 2 ];

   if( K > cache[ N ] + cache[ N - 1 ] )
   {
      std::cout << -1 << std::endl;
      return 0;
   }

   --K;

   for( uint32_t i = N; i > 0; --i )
   {
      if( K < cache[ i ] )
         std::cout << '0';
      else
      {
         std::cout << '1';
         K -= cache[ i ];
      }
   }

   std::cout << std::endl;

   return 0;
}
