#include <cstdint>
#include <iostream>
#include <unordered_map>

int main()
{
   uint32_t N, K;
   std::cin >> N >> K;

   std::unordered_map< uint32_t, uint32_t > cache0, cache1;

   cache0[ 1 ] = cache1[ 1 ] = 1;
   for( uint32_t i = 2; i <= N; ++i )
   {
      cache0[ i ] = cache0[ i - 1 ] + cache1[ i - 1];
      cache1[ i ] = cache0[ i - 1 ];
   }


   if( K > cache0[ N ] + cache1[ N ] )
   {
      std::cout << -1 << std::endl;
      return 0;
   }

   --K;

   for( uint32_t i = N; i > 1; --i )
   {
      if( K < cache0[ i ] )
         std::cout << '0';
      else
      {
         std::cout << '1';
         K -= cache0[ i ];
      }
   }

   std::cout << ( K ? '1' : '0' ) << std::endl;

   return 0;
}
