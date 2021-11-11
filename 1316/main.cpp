#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>
#include <math.h>

inline uint32_t price_to_int( float x )
{
   return static_cast< uint32_t >( floorf( x * 100.0 + 0.5 ) );
}

void update( std::vector< uint32_t >& tree,
             uint32_t v,
             uint32_t tl, uint32_t tr,
             uint32_t pos, int diff )
{
   if( tl == tr )
		tree[ v ] += diff;
	else
   {
		uint32_t tm = ( tl + tr ) / 2;
		if( pos <= tm )
			update( tree, v*2, tl, tm, pos, diff );
		else
			update( tree, v*2+1, tm+1, tr, pos, diff );
      tree[ v ] = tree[ v*2 ] + tree[ v*2+1 ];
	}
}

uint64_t sum( std::vector< uint32_t >& tree,
              uint32_t v,
              uint32_t tl, uint32_t tr,
              uint32_t l, uint32_t r )
{
   if( l > r )
		return 0;
	if( l == tl && r == tr )
		return tree[ v ];
	uint32_t tm = (tl + tr) / 2;
	return sum( tree, v*2, tl, tm, l, std::min( r, tm ) )
		    + sum( tree, v*2+1, tm+1, tr, std::max( l, tm+1 ), r);
}

int main()
{
   uint32_t const MAX = 1000000;
   std::vector< uint32_t > segment_tree( 4*MAX, 0 );

   uint64_t count = 0;

   char buf[ 5 ];
   while( true )
   {
      std::scanf( "%s", &buf );
      if( buf[ 0 ] == 'B' ) // BID X
      {
         float x;
         std::scanf( "%f", &x );

         update( segment_tree, 1, 1, MAX, price_to_int( x ), 1 );
      }
      else if( buf[ 0 ] == 'D' ) // DEL X
      {
         float x;
         std::scanf( "%f", &x );

         update( segment_tree, 1, 1, MAX, price_to_int( x ), -1 );
      }
      else if( buf[ 0 ] == 'S' ) // SALE X K
      {
         float x;
         uint32_t k;
         std::scanf( "%f %" SCNu32, &x, &k );

         auto s = sum( segment_tree, 1, 1, MAX, price_to_int( x ), MAX );
         count += std::min( static_cast< uint64_t >( k ), s );
      }
      else // QUIT
         break;
   }

   double result = count;
   result /= 100;
   std::printf( "%.2lf\n", result );

   return 0;
}
