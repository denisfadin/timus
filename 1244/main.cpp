#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <map>
#include <bitset>
#include <vector>

int main()
{
   uint32_t const MAX_SIZE = 100;
   using BitsT = std::bitset< MAX_SIZE + 1 >;

   std::map< uint32_t, BitsT > cache;

   auto set_cache = [ & ]( uint32_t w, BitsT&& bits )
   {
      auto it = cache.find( w );
      if( it != cache.end() )
         it->second.set( MAX_SIZE );
      else
         cache.emplace( w, std::move( bits ) );
   };

   uint32_t W;
   std::scanf( "%" SCNu32, &W );

   uint32_t N;
   std::scanf( "%" SCNu32, &N );

   for( uint32_t i = 0; i < N; ++i )
   {
      uint32_t w;
      std::scanf( "%" SCNu32, &w );

      std::vector< std::pair< uint32_t, BitsT > > buf;
      buf.reserve( cache.size() );
      for( auto it = cache.begin(); it != cache.end(); ++it )
      {
         BitsT bits = it->second;
         bits.set( i );
         buf.push_back( std::make_pair( it->first + w, std::move( bits ) ) );
      }

      for( auto& value : buf )
         set_cache( value.first, std::move( value.second ) );

      {
         BitsT bits;
         bits.reset();
         bits.set( i );
         set_cache( w, std::move( bits ) );
      }
   }

   auto it = cache.find( W );
   if( it == cache.end() )
   {
      std::printf( "0\n" );
   }
   else if( it->second.test( MAX_SIZE ) )
   {
      std::printf( "-1\n" );
   }
   else
   {
      auto const& bits = it->second;
      for( uint32_t i = 0; i < N; ++i )
      {
         if( bits.test( i ) )
            continue;
         std::printf( "%" PRIu32 " ", i + 1 );
      }
      std::printf( "\n" );
   }

   return 0;
}
