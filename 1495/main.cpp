#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>
#include <limits>

int main()
{
   uint32_t N;
   std::scanf( "%" SCNu32, &N );

   if( N <= 2 )
   {
      std::printf( "%" PRIu32 "\n", N );
      return 0;
   }

   auto print_result = []( uint32_t result, uint32_t i )
   {
      while( true )
      {
         if( result & ( 1 << i ) )
            std::putchar( '2' );
         else
            std::putchar( '1' );

         if( i == 0 )
            break;
         --i;
      }
      std::putchar( '\n' );
   };

   std::vector< uint32_t > data( N, std::numeric_limits< uint32_t >::max() );
   data[ 1 ] = 0;
   data[ 2 ] = 1;

   uint32_t rem10 = 1;

   for( uint32_t i = 1; i < 30; ++i )
   {
      rem10 = ( rem10 * 10 ) % N;

      std::vector< uint32_t > new_data( N, std::numeric_limits< uint32_t >::max() );

      for( uint32_t j = 1; j < N; ++j )
      {
         if( data[ j ] == std::numeric_limits< uint32_t >::max() )
            continue;

         uint32_t rem = ( j + rem10 ) % N;
         if( new_data[ rem ] == std::numeric_limits< uint32_t >::max() )
            new_data[ rem ] = data[ j ];
      }

      uint32_t rem20 = ( rem10 << 1 ) % N;
      for( uint32_t j = 1; j < N; ++j )
      {
         if( data[ j ] == std::numeric_limits< uint32_t >::max() )
            continue;

         uint32_t rem = ( j + rem20 ) % N;
         if( new_data[ rem ] == std::numeric_limits< uint32_t >::max() )
            new_data[ rem ] = data[ j ] | ( 1 << i );
      }

      if( new_data[ 0 ] != std::numeric_limits< uint32_t >::max() )
      {
         print_result( new_data[ 0 ], i );
         return 0;
      }

      std::swap( data, new_data );
   }

   std::printf( "Impossible\n" );

   return 0;
}
