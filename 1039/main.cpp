#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>
#include <list>
#include <unordered_map>

#ifndef SCNd8
  #define SCNd8 "hhd"
#endif

std::pair< int32_t, int32_t > DP( uint16_t employee,
                                  std::vector< int8_t > const& ratings,
                                  std::vector< std::list< uint16_t > > const& tree )
{
   std::pair< int32_t, int32_t > result( ratings[ employee ], 0 );
   if( tree[ employee ].empty() )
      return result;

   static std::unordered_map< uint16_t, std::pair< int32_t, int32_t > > cache;
   auto cache_it = cache.find( employee );
   if( cache_it != cache.end() )
      return cache_it->second;

   for( auto const& e : tree[ employee ] )
   {
      auto dp_e = DP( e, ratings, tree );

      if( dp_e.second > 0 )
         result.first += dp_e.second;

      result.second = std::max( result.second, result.second + std::max( dp_e.first, dp_e.second ) );
   }

   cache[ employee ] = result;
   return result;
}

int main()
{
   uint16_t N;
   std::scanf( "%" SCNu16, &N );

   std::vector< int8_t > ratings( N+1, 0 );
   for( uint16_t i = 1; i <= N; ++i )
      std::scanf( "%" SCNd8, &ratings[ i ] );

   std::vector< bool > has_immediate_supervisor( N + 1, false );
   std::vector< std::list< uint16_t > > tree( N+1 );
   while( true )
   {
      uint16_t a, b;
      std::scanf( "%" SCNu16 "%" SCNu16, &a, &b );
      if( !a && !b )
         break;
      tree[ b ].push_back( a );
      has_immediate_supervisor[ a ] = true;
   }

   uint16_t root = 1;
   while( true )
   {
      if( !has_immediate_supervisor[ root ] )
         break;
      ++root;
   }

   auto result = DP( root, ratings, tree );
   std::printf( "%" PRId32 "\n", std::max( result.first, result.second ) );

   return 0;
}
