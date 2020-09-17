#include <cinttypes>
#include <limits>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstdio>

class DSU
{
public:

   // создать систему с size независимыми множествами
   DSU( uint32_t size );

   // Найти "родителя" (множество) для x
   uint32_t Find( uint32_t x ) const;

   // объединить два множеста, содержащих x и y
   void Union( uint32_t x, uint32_t y );

   uint32_t Size() const;

private:

   std::vector< uint32_t > mParents;
   uint32_t mSize;
};

DSU::DSU( uint32_t size ) : mSize( size )
{
   mParents.resize( mSize, std::numeric_limits< uint32_t >::max() );
}

uint32_t DSU::Find( uint32_t x ) const
{
   uint32_t current = x;
   while( true )
   {
      uint32_t parent = mParents[ current ];
      if( parent == std::numeric_limits< uint32_t >::max() )
         break;
      current = parent;
   }
   return current;
}

void DSU::Union( uint32_t x, uint32_t y )
{
   uint32_t parent_x = Find( x );
   uint32_t parent_y = Find( y );

   if( parent_x == parent_y )
      return;

   auto x_to_y = []() -> bool
   {
      return std::rand() % 2;
   };

   if( x_to_y() )
      mParents[ parent_x ] = parent_y;
   else
      mParents[ parent_y ] = parent_x;

   --mSize;
}

uint32_t DSU::Size() const
{
   return mSize;
}

int main()
{
   std::srand( std::time( nullptr ) );

   uint32_t N, M;
   scanf( "%" SCNu32 "%" SCNu32, &N, &M );

   std::vector< std::pair< uint32_t, uint32_t > > edges;
   edges.reserve( M );
   for( uint32_t i = 0; i < M; ++i )
   {
      uint32_t x, y;
      scanf( "%" SCNu32 "%" SCNu32, &x, &y );
      --x;
      --y;
      edges.push_back( std::make_pair( x, y ) );
   }

   uint32_t Q;
   scanf( "%" SCNu32, &Q );

   std::vector< uint32_t > tasks;
   tasks.reserve( Q );

   std::vector< bool > to_be_removed;
   to_be_removed.resize( M, false );
   for( uint32_t i = 0; i < Q; ++i )
   {
      uint32_t e;
      scanf( "%" SCNu32, &e );
      --e;
      tasks.push_back( e );

      to_be_removed[ e ] = true;
   }

   DSU dsu( N );
   for( uint32_t i = 0; i < M; ++i )
   {
      if( !to_be_removed[ i ] )
      {
         auto const& edge = edges[ i ];
         dsu.Union( edge.first, edge.second );
      }
   }

   std::vector< uint32_t > result;
   result.reserve( Q );

   for( auto it = tasks.rbegin(); it != tasks.rend(); ++it )
   {
      result.push_back( dsu.Size() );

      auto const& edge = edges[ *it ];
      dsu.Union( edge.first, edge.second );
   }

   for( auto it = result.rbegin(); it != result.rend(); ++it )
      printf( "%" PRIu32 " ", *it );

   printf( "\n" );

   return 0;
}
