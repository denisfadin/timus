#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>
#include <unordered_map>
#include <list>
#include <algorithm>

int main()
{
   uint16_t N;
   uint32_t M;
   scanf( "%" SCNu16 "%" SCNu32, &N, &M );

   std::unordered_map< uint16_t, std::vector< std::pair< uint16_t, uint16_t > > > edges;
   edges.reserve( N );

   for( uint32_t i = 0; i < M; ++i )
   {
      uint16_t a, b, c;
      scanf( "%" SCNu16 "%" SCNu16 "%" SCNu16, &a, &b, &c );
      --a;
      --b;

      edges[ a ].emplace_back( std::make_pair( b, c ) );
   }

   uint16_t S, F;
   scanf( "%" SCNu16 "%" SCNu16, &S, &F );
   --S;
   --F;

   std::vector< uint64_t > distance( N, 0 );

   std::list< uint16_t > queue;
   queue.push_back( S );

   while( !queue.empty() )
   {
      uint16_t current = queue.front();
      queue.pop_front();
      uint64_t current_distance = distance[ current ];
      auto const& current_edges = edges[ current ];

      for( auto const& edge : current_edges )
      {
         uint64_t d = current_distance + edge.second;
         if( distance[ edge.first ] < d )
            distance[ edge.first ] = d;
         if( std::find( queue.begin(), queue.end(), edge.first ) == queue.end() )
            queue.push_back( edge.first );
      }
   }

   if( distance[ F ] )
      printf( "%" PRIu64 "\n", distance[ F ] );
   else
      printf( "No solution\n" );

   return 0;
}
