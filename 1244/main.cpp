#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>
#include <map>

int main()
{
   uint32_t W;
   std::scanf( "%" SCNu32, &W );

   std::map< uint32_t, std::vector< bool > > cache;

   auto set_cache = [ & ]( uint32_t w, std::vector< bool >&& bits )
   {
      auto it = cache.find( w );
      if( it != cache.end() )
         it->second.clear();
      else
         cache.emplace( w, std::move( bits ) );
   };

   uint32_t N;
   std::scanf( "%" SCNu32, &N );

   for( uint32_t i = 0; i < N; ++i )
   {
      uint32_t w;
      std::scanf( "%" SCNu32, &w );

      for( auto it = cache.begin(); it != cache.end(); ++it )
      {   
         std::vector< bool > bits = it->second;

         if( !bits.empty() )
         {
            if( bits[ i ] )
               continue;
            bits[ i ] = true;
         }
         set_cache( it->first + w, std::move( bits ) );
      }

      {
         std::vector< bool > bits( N, false );
         bits[ i ] = true;
         set_cache( w, std::move( bits ) );
      }
   }

   auto it = cache.find( W );
   if( it == cache.end() )
   {
      std::printf( "0\n" );
   }
   else if( it->second.empty() )
   {
      std::printf( "-1\n" );
   }
   else
   {
      auto const& bits = it->second;
      for( uint32_t i = 0; i < bits.size(); ++i )
      {
         if( bits[ i ] )
            continue;

         std::printf( "%" PRIu32 " ", i+1 );
      }
      std::printf( "\n" );
   }

   return 0;
}
