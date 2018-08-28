#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>
#include <algorithm>

int main()
{
   uint16_t n;
   scanf( "%" SCNu16, &n );

   std::vector< std::vector< uint16_t > > routes;
   routes.resize( n );

   uint16_t MAX_STOP = 10001;
   std::vector< bool > stops( n*MAX_STOP, false );

   uint32_t result_size = 0;

   for( uint16_t i = 0; i < n; ++i )
   {
      uint16_t m;
      scanf( "%" SCNu16, &m );

      result_size += m;

      auto& route = routes.at( i );
      route.resize( m );

      auto const idx = i*MAX_STOP;
      for( uint16_t j = 0; j < m; ++j )
      {
         scanf( "%" SCNu16, &route[j] );
         stops.at( idx + route[j] ) = true;
      }
      scanf( "%" SCNu16, &route[0] );
   }

   std::vector< uint16_t > result;
   result.reserve( result_size );

   result.insert( result.begin(), routes.at(0).begin(), routes.at(0).end() );

   /*printf( "%" PRIu16 "(): ", 0 );
   for( auto const stop : result )
      printf( "%" PRIu16 " ", stop );
   printf( "\n" );*/

   for( uint16_t i = 1; i < n; ++i )
   {
      auto const idx = i*MAX_STOP;
      auto const& route = routes.at( i );

      auto it = result.begin();
      while( it != result.end() )
      {
         if( stops.at( idx + *it ) )
         {
            auto finded_it = std::find( route.begin(), route.end(), *it );
            result.insert( it + 1, finded_it + 1, route.end() );
            result.insert( it + 1 + std::distance( finded_it + 1, route.end() ), route.begin(), finded_it + 1 );

            /*printf( "%" PRIu16 "(%" PRIu16 "): ", i, *it );
            for( auto const stop : result )
               printf( "%" PRIu16 " ", stop );
            printf( "\n" );*/

            break;
         }
         ++it;
      }
      if( it == result.end() )
      {
         printf( "0\n" );
         return 0;
      }
   }

   printf( "%" PRIu32 " ", static_cast<uint32_t>( result.size() ) );
   for( auto const stop : result )
      printf( "%" PRIu16 " ", stop );
   printf( "%" PRIu16 "\n", result[0] );

   return 0;
}
