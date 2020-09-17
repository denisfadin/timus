#include <cinttypes>
#include <iostream>
#include <vector>
#include <limits>

class Matrix
{
public:

   Matrix( uint32_t size )
      : mSize( size ),
        mData( mSize * mSize, 0 )
   {}

   uint32_t Get( uint32_t i, uint32_t j ) const
   {
      return mData[ i*mSize + j ];
   }

   void Set( uint32_t i, uint32_t j, uint32_t value )
   {
      mData[ i*mSize + j ] = value;
   }

private:

   uint32_t mSize;
   std::vector< uint32_t > mData;
};

int main()
{
   uint32_t N, K;
   std::cin >> N >> K;

   std::vector< uint32_t > electrified_cities;
   for( uint32_t i = 0; i < K; ++i )
   {
      uint32_t v;
      std::cin >> v;
      --v;
      electrified_cities.push_back( v );
   }

   Matrix graph( N );

   for( uint32_t i = 0; i < N; ++i )
   {
      for( uint32_t j = 0; j < N; ++j )
      {
         uint32_t v;
         std::cin >> v;
         graph.Set( i, j, v );
      }
   }

   std::vector< uint32_t > cities( N, std::numeric_limits< uint32_t >::max() );
   for( auto const c : electrified_cities )
   {
      for( uint32_t i = 0; i < N; ++i )
      {
         auto const v = graph.Get( c, i );
         if( cities[ i ] > v )
            cities[ i ] = v;
      }
   }

   uint32_t result = 0;

   for( uint32_t iter = 0; iter < N-K; ++iter )
   {
      uint32_t city = 0;
      uint32_t cost = std::numeric_limits< uint32_t >::max();

      for( uint32_t i = 0; i < N; ++i )
      {
         auto const v = cities[ i ];
         if( v == 0 )
            continue;
         if( v < cost )
         {
            cost = v;
            city = i;
         }
      }

      result += cost;

      for( uint32_t i = 0; i < N; ++i )
      {
         auto const v = graph.Get( city, i );
         if( cities[ i ] > v )
            cities[ i ] = v;
      }
   }

   std::cout << result << std::endl;

   return 0;
}
