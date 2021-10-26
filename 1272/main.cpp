#include <cstdio>
#include <cstdint>
#include <cinttypes>
#include <vector>
#include <algorithm>

int main()
{
   uint32_t N, K, M;
   std::scanf( "%" SCNu32 " %" SCNu32 " %" SCNu32, &N, &K, &M );

   std::vector< uint32_t > data( N+1 );
   for( uint32_t i = 0; i <= N; ++i )
      data[ i ] = i;

   auto process = [ &data, &N ]( uint32_t sz )
   {
      uint32_t result = 0;
      for( uint32_t i = 0; i < sz; ++i )
      {
         uint32_t u, v;
         std::scanf( "%" SCNu32 " %" SCNu32, &u, &v );

         auto du = data[ u ];
         auto dv = data[ v ];

         if( du == dv )
            continue;

         ++result;

         std::replace( data.begin(), data.end(), dv, du );
      }
      return result;
   };

   process( K );

   std::printf( "%" PRIu32 "\n", process( M ) );

   return 0;
}
