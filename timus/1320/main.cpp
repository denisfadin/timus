#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>
#include <algorithm>

int main()
{
   std::vector< std::pair< uint16_t, uint16_t > > edges;
   {
      uint16_t x, y;
      while( scanf( "%" SCNu16 "%" SCNu16, &x, &y ) != EOF )
         edges.emplace_back( x, y );
   }

   std::vector< bool > processed( edges.size(), false );

   while( true )
   {
      std::vector< uint16_t > queue;
      {
         auto edge_to_process = std::find( processed.begin(), processed.end(), false );
         if( edge_to_process == processed.end() )
            break;
         auto idx = std::distance( processed.begin(), edge_to_process );
         queue.push_back( edges[ idx ].first );
         queue.push_back( edges[ idx ].second );
         processed[ idx ] = true;
      }

      uint16_t count = 1;
      for( uint16_t i = 0; i < queue.size(); ++i )
      {
         auto v = queue[ i ];
         for( uint16_t j = 0; j < edges.size(); ++j )
         {
            if( processed[ j ] )
               continue;
            auto const& edge = edges[ j ];
            if( edge.first == v || edge.second == v )
            {
               ++count;
               processed[ j ] = true;
               if( std::find( queue.begin(), queue.end(), edge.first == v ? edge.second : edge.first ) == queue.end() )
                  queue.push_back( edge.first == v ? edge.second : edge.first );
            }
         }
      }
      if( count % 2 )
      {
         printf( "0\n" );
         return 0;
      }
   }

   printf( "1\n" );

   return 0;
}
