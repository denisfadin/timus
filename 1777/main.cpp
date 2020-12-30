#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>
#include <limits>
#include <algorithm>

int main()
{
   std::vector< uint64_t > data( 3 );
   for( uint32_t i = 0; i < data.size(); ++i )
      std::scanf( "%" SCNu64, &data[ i ] );

   uint32_t result = 0;
   while( true )
   {
      ++result;
      std::sort( data.begin(), data.end() );

      uint64_t diff = std::numeric_limits< uint64_t >::max();
      for( uint32_t i = 0; i < data.size() - 1; ++i )
         diff = std::min( diff, data[ i + 1 ] - data[ i ] );

      if( diff == 0 )
         break;

      data.push_back( diff );
   }

   std::printf( "%" PRIu32 "\n", result );

   return 0;
}
