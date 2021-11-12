#pragma comment(linker, "/STACK:16777216")

#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <unordered_map>
#include <list>
#include <vector>
#include <limits>

struct Node
{
   uint16_t vertex;
   uint16_t weight;
};

void Preprocess( std::unordered_map< uint16_t, std::list< Node > >& tree,
                 uint16_t vertex,
                 std::vector< uint32_t >& D,
                 std::vector< uint32_t >& I )
{
   for( auto const& node : tree[ vertex ] )
   {
      if( I[ node.vertex ] != std::numeric_limits< uint32_t >::max() )
         continue;
      I[ node.vertex ] = D.size();
      D.push_back( D.back() + node.weight );
      Preprocess( tree, node.vertex, D, I );
      D.push_back( D[ I[ vertex ] ] );
   }
}

void build_segment_tree( std::vector< uint32_t >& segment_tree,
                         std::vector< uint32_t >& D,
                         uint32_t v,
                         uint32_t tl, uint32_t tr )
{
   if( tl == tr )
      segment_tree[ v ] = D[ tl ];
   else
   {
      uint32_t tm = ( tl + tr ) / 2;
      build_segment_tree( segment_tree, D, 2*v+1, tl, tm );
      build_segment_tree( segment_tree, D, 2*v+2, tm+1, tr );
      segment_tree[ v ] = std::min( segment_tree[ 2*v+1 ], segment_tree[ 2*v+2 ] );
   }
}

uint32_t find_min( std::vector< uint32_t >& segment_tree,
                   uint32_t v,
                   uint32_t tl, uint32_t tr,
                   uint32_t l, uint32_t r )
{
   if( l > r )
		return std::numeric_limits< uint32_t >::max();
	if( l == tl && r == tr )
		return segment_tree[ v ];

	uint32_t tm = ( tl + tr ) / 2;
	return std::min( find_min( segment_tree, v*2+1, tl, tm, l, std::min( r,tm ) ),
		              find_min( segment_tree, v*2+2, tm+1, tr, std::max( l, tm+1), r ) );
}

int main()
{
   std::unordered_map< uint16_t, std::list< Node > > tree;

   uint32_t N;
   std::scanf( "%" SCNu32, &N );

   for( uint16_t i = 0; i < N-1; ++i )
   {
      uint16_t u, v, w;
      std::scanf( "%" SCNu16 " %" SCNu16 " %" SCNu16, &u, &v, &w );

      tree[ u ].push_back( Node{ .vertex = v, .weight = w } );
      tree[ v ].push_back( Node{ .vertex = u, .weight = w } );
   }

   std::vector< uint32_t > D;
   std::vector< uint32_t > I( N, std::numeric_limits< uint32_t >::max() );

   D.push_back( 0 );
   I[ 0 ] = 0;
   Preprocess( tree, 0, D, I );

   std::vector< uint32_t > segment_tree( 4 * D.size() );
   build_segment_tree( segment_tree, D, 0, 0, D.size()-1 );

   uint32_t M;
   std::scanf( "%" SCNu32, &M );

   for( uint32_t i = 0; i < M; ++i )
   {
      uint16_t u, v;
      std::scanf( "%" SCNu16 " %" SCNu16, &u, &v );

      uint32_t result = D[ I[u] ] + D[ I[v] ];
      result -= 2 * find_min( segment_tree, 0, 0, D.size()-1, std::min( I[u], I[v] ), std::max( I[u], I[v] ) );

      std::printf( "%" PRIu32 "\n", result );
   }

   return 0;
}
