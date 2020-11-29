#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>
#include <array>
#include <limits>

using EdgeT = std::pair< uint16_t, uint16_t >;

class Calculator
{
public:
   Calculator( std::vector< std::array< EdgeT, 3 > >&& edges )
      : mEdges( edges ),
        mCache( ( mEdges.size() + 2 ) * mEdges.size(), std::numeric_limits< uint32_t >::max() )
   {}

   uint32_t Do( uint16_t v, uint16_t q, uint16_t v_prev );

private:
      std::vector< std::array< EdgeT, 3 > > mEdges;
      std::vector< uint32_t > mCache;
};

uint32_t Calculator::Do( uint16_t v, uint16_t q, uint16_t v_prev )
{
   if( q == 0 )
      return 0;

   auto& cache_data = mCache[ v * mEdges.size() + q - 1 ];
   if( cache_data != std::numeric_limits< uint32_t >::max() )
      return cache_data;

   auto& v_edges = mEdges[ v ];

   EdgeT* e1 = nullptr;
   EdgeT* e2 = nullptr;
   for( uint16_t i = 0; i < 3; ++i )
      if( v_edges[ i ].first != 0 && v_edges[ i ].first != v_prev )
      {
         if( e1 == nullptr )
            e1 = &v_edges[ i ];
         else
            e2 = &v_edges[ i ];
      }

   uint32_t result = 0;
   if( e1 || e2 )
   {
      if( q == 1 )
      {
         if( e1 )
            result = std::max( result, static_cast< uint32_t >( e1->second ) );
         if( e2 )
            result = std::max( result, static_cast< uint32_t >( e2->second ) );
      }
      else // q > 1
      {
         if( e1 )
         {
            uint32_t res = e1->second + Do( e1->first, q - 1, v );
            result = std::max( result, res );
         }

         if( e2 )
         {
            uint32_t res = e2->second + Do( e2->first, q - 1, v );
            result = std::max( result, res );
         }

         if( e1 && e2 )
         {
            for( uint32_t i = 0; i <= q - 2; ++i )
            {
               uint32_t res = e1->second + e2->second;
               res += Do( e1->first, i, v );
               res += Do( e2->first, q - 2 - i, v );

               result = std::max( result, res );
            }
         }
      }
   }

   cache_data = result;
   return cache_data;
}

int main()
{
   uint16_t N, Q;
   std::scanf( "%" SCNu16 "%" SCNu16, &N, &Q );

   std::vector< std::array< EdgeT, 3 > > edges( N + 1 );
   for( uint32_t i = 1; i <= N; ++i )
      edges[ i ].fill( std::make_pair( 0, 0 ) );
   for( uint16_t i = 0; i < N-1; ++i )
   {
      uint16_t a, b, count;
      std::scanf( "%" SCNu16 "%" SCNu16 "%" SCNu16, &a, &b, &count );

      for( uint16_t i = 0; i < 3; ++i )
         if( edges[ a ][ i ].first == 0 )
         {
            edges[ a ][ i ] = std::make_pair( b, count );
            break;
         }

      for( uint16_t i = 0; i < 3; ++i )
         if( edges[ b ][ i ].first == 0 )
         {
            edges[ b ][ i ] = std::make_pair( a, count );
            break;
         }
   }

   Calculator calc( std::move( edges ) );

   std::printf( "%" PRIu32 "\n", calc.Do( 1, Q, 0 ) );

   return 0;
}
