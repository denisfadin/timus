#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>
#include <algorithm>
#include <map>
#include <limits>

using SegmentT = std::pair< int32_t, int32_t >;

int main()
{
   int32_t M;
   std::scanf( "%" SCNd32, &M );

   std::vector< SegmentT > segments;
   segments.reserve( 99999 );

   while( true )
   {
      int32_t l, r;
      std::scanf( "%" SCNd32 "%" SCNd32, &l, &r );
      if( l == 0 && r == 0 )
         break;
      if( l >= M || r <= 0 )
         continue;
      if( l == r )
         continue;
      segments.push_back( std::make_pair( std::move( l ), std::move( r ) ) );
   }

   std::sort( segments.begin(), segments.end(), []( SegmentT const& a, SegmentT const& b )
   {
      return a.first < b.first;
   });

   struct CacheData
   {
      uint32_t mCount;
      uint32_t mSegmentPos;
      std::map< int32_t, CacheData >::iterator mPrev;
   };
   std::map< int32_t, CacheData > cache;

   for( uint32_t i = 0; i < segments.size(); ++i )
   {
      auto const& segment = segments[ i ];
      if( segment.first <= 0 )
         cache[ segment.second ] = CacheData{ .mCount = 1,
                                              .mSegmentPos = i,
                                              .mPrev = cache.end() };
      else
      {
         CacheData data;
         data.mCount = std::numeric_limits< uint32_t >::max();
         data.mSegmentPos = i;

         for( auto it = cache.lower_bound( segment.first ); it != cache.end(); ++it )
         {
            if( it->first > segment.second )
               break;
            if( data.mCount > it->second.mCount + 1 )
            {
               data.mCount = it->second.mCount + 1;
               data.mPrev = it;
            }
         }

         if( data.mCount != std::numeric_limits< uint32_t >::max() )
         {
            auto it = cache.find( segment.second );
            if( it == cache.end() || it->second.mCount > data.mCount )
               cache[ segment.second ] = std::move( data );
         }
      }
   }

   auto result_cache_it = cache.lower_bound( M );
   if( result_cache_it == cache.end() )
      std::printf( "No solution\n" );
   else
   {
      for( auto it = result_cache_it; it != cache.end(); ++it )
         if( it->second.mCount < result_cache_it->second.mCount )
            result_cache_it = it;
      std::printf( "%" PRIu32 "\n", result_cache_it->second.mCount );
      std::vector< uint32_t > result_segments;
      while( result_cache_it != cache.end() )
      {
         result_segments.push_back( result_cache_it->second.mSegmentPos );
         result_cache_it = result_cache_it->second.mPrev;
      }
      for( auto it = result_segments.rbegin(); it != result_segments.rend(); ++it )
      {
         auto const& segment = segments[ *it ];
         std::printf( "%" PRId32 " %" PRId32 "\n", segment.first, segment.second );
      }
   }

   return 0;
}
