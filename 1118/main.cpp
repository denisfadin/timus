#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>

int main()
{
   uint32_t I, J;
   std::scanf( "%" SCNu32 " %" SCNu32, &I, &J );

   std::vector< uint32_t > buf( J+1, 0 );
   for( uint32_t i = 2; i <= J; ++i )
   {
      buf[ i ] += 1;
      for( uint32_t j = i + i; j <= J; j += i )
         buf[ j ] += i;
   }

   float min = static_cast< float >( buf[ I ] ) / I;
   uint32_t min_idx = I;
   for( uint32_t i = I+1; i <= J; ++i )
   {
      float tmp = static_cast< float >( buf[ i ] ) / i;
      if( min > tmp )
      {
         min = tmp;
         min_idx = i;
      }
   }

   std::printf( "%" PRIu32 "\n", min_idx );

   return 0;
}
