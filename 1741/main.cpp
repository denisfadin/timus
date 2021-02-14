#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>
#include <algorithm>
#include <limits>

int main()
{
   uint16_t N, M;
   std::scanf( "%" SCNu16 "%" SCNu16, &N, &M );

   struct Update
   {
      uint16_t x;
      uint16_t y;
      uint32_t d;
      char s;
   };

   std::vector< Update > update_list( M );
   std::vector< char > tmp_buffer( 10, 0 );
   for( uint16_t i = 0; i < M; ++i )
   {
      auto& u = update_list[ i ];
      std::scanf( "%" SCNu16 "%" SCNu16 "%" SCNu32 "%s", &u.x, &u.y, &u.d, tmp_buffer.data() );
      u.s = tmp_buffer[ 0 ];
   }

   std::sort( update_list.begin(), update_list.end(), []( Update const& a, Update const& b )
   {
      return a.x < b.x;
   });

   std::vector< uint64_t > dp_lic( N + 1, std::numeric_limits< uint64_t >::max() );
   std::vector< uint64_t > dp_pir( N + 1, std::numeric_limits< uint64_t >::max() );
   dp_lic[ 1 ] = 0;
   dp_pir[ 1 ] = 0;

   for( auto const& update : update_list )
   {
      if( update.s == 'L' || update.s == 'C' )
      {
         if( dp_lic[ update.x ] != std::numeric_limits< uint64_t >::max() )
            dp_lic[ update.y ] = std::min( dp_lic[ update.y ], dp_lic[ update.x ] + update.d );
      }

      if( update.s == 'P' || update.s == 'C' )
      {
         if( dp_pir[ update.x ] != std::numeric_limits< uint64_t >::max() )
            dp_pir[ update.y ] = std::min( dp_pir[ update.y ], dp_pir[ update.x ] + update.d );

         if( dp_lic[ update.x ] != std::numeric_limits< uint64_t >::max() )
            dp_pir[ update.y ] = std::min( dp_pir[ update.y ], dp_lic[ update.x ] + update.d );
      }
   }

   uint64_t result = std::min( dp_lic[ N ], dp_pir[ N ] );

   if( result == std::numeric_limits< uint64_t >::max() )
      std::printf( "Offline\n" );
   else
      std::printf( "Online\n%" PRIu64 "\n", result );

   return 0;
}
