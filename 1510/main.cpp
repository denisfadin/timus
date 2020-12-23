#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <unordered_map>

int main()
{
   uint32_t N;
   std::scanf( "%" SCNu32, &N );

   std::unordered_map< uint32_t, uint32_t > cache;
   cache.reserve( N >> 1 );
   uint32_t k;
   for( uint32_t i = 0; i < N; ++i )
   {
      std::scanf( "%" SCNu32, &k );
      auto it = cache.find( k );
      if( it == cache.end() )
         it = cache.emplace( k, 0 ).first;
      it->second += 1;
   }
   auto result = cache.begin();
   for( auto it = cache.begin(); it != cache.end(); ++it )
      if( result->second < it->second )
         result = it;

   std::printf( "%" PRIu32 "\n", result->first );

   return 0;
}
