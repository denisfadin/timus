#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>
#include <algorithm>

class DSU
{
public:

   DSU( uint32_t N )
      : mParents( N )
   {
      for( uint32_t i = 0; i < mParents.size(); ++i )
         mParents[ i ] = i;
   }

   uint32_t Find( uint32_t x ) const
   {
      uint32_t result = x;
      while( result != mParents[ result ] )
         result = mParents[ result ];
      return result;
   }

   bool Union( uint32_t x, uint32_t y )
   {
      uint32_t px = Find( x );
      uint32_t py = Find( y );
      if( px == py )
         return false;
      mParents[ py ] = px;
      return true;
   }

private:

   std::vector< uint32_t > mParents;
};

struct Edge
{
   uint32_t x;
   uint32_t y;
   uint32_t l;
};

int main()
{
   uint32_t N, M;
   std::scanf( "%" SCNu32 " %" SCNu32, &N, &M );

   std::vector< Edge > edges( M );
   for( uint32_t i = 0; i < M; ++i )
   {
      auto& e = edges[ i ];
      std::scanf( "%" SCNu32 " %" SCNu32 " %" SCNu32, &e.x, &e.y, &e.l );
   }

   std::sort( edges.begin(), edges.end(), []( Edge const& a, Edge const& b )
   {
      return a.l < b.l;
   });

   uint32_t result = 0;
   std::vector< Edge const* > result_list;

   DSU dsu( N+1 );
   for( uint32_t i = 0; i < M; ++i )
   {
      auto const& e = edges[ i ];
      if( dsu.Union( e.x, e.y ) )
      {
         result = std::max( result, e.l );
         result_list.push_back( &e );
      }
   }

   std::printf( "%" PRIu32 "\n", result );
   std::printf( "%" PRIu32 "\n", result_list.size() );
   for( uint32_t i = 0; i < result_list.size(); ++i )
   {
      auto const& e = *result_list[ i ];
      std::printf( "%" PRIu32 " %" PRIu32 "\n", e.x, e.y );
   }

   return 0;
}
