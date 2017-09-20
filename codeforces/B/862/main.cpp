#include <stdio.h>
#include <stdint.h>
#include <unordered_map>
#include <vector>
#include <functional>

int main()
{
   int32_t n;
   scanf( "%d", &n );

   std::unordered_map< int32_t, std::vector< int32_t > > tree;

   for( int32_t i = 0; i < n-1; ++i )
   {
      int32_t x, y;
      scanf( "%d%d", &x, &y );

      tree[ x ].push_back( y );
      tree[ y ].push_back( x );
   }

   std::vector< bool > processed( n+1, false );

   int32_t a = 0;
   std::function< void( int32_t const&, bool ) > do_process = [&]( int32_t const& i, bool be_a ) -> void
   {
      if( !processed[i] )
      {
         processed[i] = true;

         if( be_a )
            ++a;

         for( auto const& v : tree[i] )
            do_process( v, !be_a );
      }
   };

   do_process( 1, true );

   printf( "%d\n", a*(n-a)-(n-1) );
}
