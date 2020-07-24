#include <cstdio>
#include <cinttypes>
#include <unordered_map>
#include <vector>

int main()
{
   int32_t n;
   scanf( "%" SCNd32, &n );

   std::unordered_map< int32_t, std::vector< int32_t > > tree;

   for( int32_t i = 0; i < n-1; ++i )
   {
      int32_t x, y;
      scanf( "%" SCNd32 "%" SCNd32, &x, &y );

      tree[ x ].push_back( y );
      tree[ y ].push_back( x );
   }

   std::vector< bool > processed( n+1, false );
   std::vector< std::pair< int32_t, bool > > stack;

   stack.push_back( std::make_pair( 1, true ) );

   int32_t a = 0;

   while( !stack.empty() )
   {
      auto const p = stack.back();
      stack.pop_back();

      if( !processed[ p.first ] )
      {
         processed[ p.first ] = true;
         if( p.second )
            ++a;

         for( auto const& v : tree[ p.first ] )
         {
            if( !processed[v] )
               stack.emplace_back( std::make_pair( v, !p.second ) );
         }
      }
   }

   printf( "%" PRId64 "\n", static_cast<int64_t>(a)*static_cast<int64_t>(n-a)-(n-1) );
}
