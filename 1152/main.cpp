#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>
#include <limits>
#include <unordered_map>

uint32_t Do( uint32_t const map,
             std::vector< uint32_t > const& monsters,
             std::vector< uint32_t > const& shots )
{
   if( map == 0 )
      return 0;

   static std::unordered_map< uint32_t, uint32_t > cache;
   auto it = cache.find( map );
   if( it != cache.end() )
      return it->second;

   uint32_t result = std::numeric_limits< uint32_t >::max();
   for( auto const shot : shots )
   {
      if( ( map & shot ) == 0 )
         continue;

      uint32_t new_map = map & (~shot);

      uint32_t res = 0;
      uint32_t m = 1;
      for( uint32_t i = 0; i < monsters.size(); ++i )
      {
         if( m & new_map )
            res += monsters[ i ];
         m <<= 1;
      }
      res += Do( new_map, monsters, shots );
      if( res < result )
         result = res;
   }

   cache[ map ] = result;

   return result;
}

int main()
{
   uint32_t N;
   std::scanf( "%" SCNu32, &N );

   std::vector< uint32_t > monsters( N, 0 );
   for( uint32_t i = 0; i < N; ++i )
      std::scanf( "%" SCNu32, &monsters[ i ] );

   std::vector< uint32_t > shots;
   {
      uint32_t m = 7; // 111 в двоичном представлении
      for( uint32_t i = 1; i < N - 1; ++i )
      {
         shots.push_back( m );
         m <<= 1;
      }

      if( N > 3 )
      {
         m = 1 << ( N - 1 );
         m |= 3;
         shots.push_back( m );

         m = 3 << ( N - 2 );
         m |= 1;
         shots.push_back( m );
      }
   }

   uint32_t map = 7; // 111 в двоичном представлении
   for( uint32_t i = 3; i < N; ++i )
   {
      map <<= 1;
      map |= 1;
   }

   std::printf( "%" PRIu32 "\n", Do( map, monsters, shots ) );

   return 0;
}
