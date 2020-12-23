#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>
#include <algorithm>

int main()
{
   uint16_t N;
   std::scanf( "%" SCNu16, &N );

   std::vector< uint16_t > result( N, 0 );

   std::vector< uint16_t > data;
   data.reserve( N );
   std::vector< uint16_t > local_data;
   uint16_t local_y = 0;
   for( uint16_t i = 0; i < N; ++ i )
   {
      uint16_t x, y;
      std::scanf( "%" SCNu16 "%" SCNu16, &x, &y );

      if( y != local_y )
      {
         data.insert( data.end(), local_data.begin(), local_data.end() );
         local_data.clear();
         std::sort( data.begin(), data.end() );
         local_y = y;
      }

      uint16_t res = local_data.size();
      auto it = std::lower_bound( data.begin(), data.end(), x );
      while( it != data.end() && *it == x )
         ++it;
      res += std::distance( data.begin(), it );

      result[ res ] += 1;

      local_data.push_back( x );
   }


   for( uint16_t i = 0; i < N; ++i )
      std::printf( "%" PRIu16 "\n", result[ i ] );

   return 0;
}
