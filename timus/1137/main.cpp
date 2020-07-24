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

   uint32_t result_size = 0;

   for( uint16_t i = 0; i < n; ++i )
   {
      uint16_t m;
      scanf( "%" SCNu16, &m );

      result_size += m;

      auto& route = routes.at( i );
      route.resize( m );

      for( uint16_t j = 0; j < m; ++j )
         scanf( "%" SCNu16, &route[j] );
      scanf( "%" SCNu16, &route[0] );
   }

   std::vector< uint16_t > result;
   result.reserve( result_size+1 );

   result.push_back( routes.at(0).front() );

   for( uint16_t i = 0; i < n; ++i )
   {
      for( uint16_t j = 0; j < n; ++j )
      {
         auto& route = routes.at( j );
         if( route.size() == 0 )
            continue;

         auto it = result.begin();
         while( it != result.end() )
         {
            auto finded_it = std::find( route.begin(), route.end(), *it );
            if( finded_it != route.end() )
            {
               result.insert( it, finded_it, route.end() );
               result.insert( it + std::distance( finded_it, route.end() ), route.begin(), finded_it );
               route.clear();
               break;
            }
            ++it;
         }
         if( it != result.end() )
            break;
      }
   }

   printf( "%" PRIu32 " ", static_cast<uint32_t>( result.size()-1 ) );
   for( auto const stop : result )
      printf( "%" PRIu16 " ", stop );
   printf( "\n" );
   return 0;
}
