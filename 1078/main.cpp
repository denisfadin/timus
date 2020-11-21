#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>
#include <utility>
#include <algorithm>
#include <limits>

int main()
{
   uint16_t N;
   std::scanf( "%" SCNu16, &N );

   using SegmentT = std::pair< int16_t, int16_t >;

   std::vector< SegmentT > segments( N );
   for( uint16_t i = 0; i < N; ++i )
      std::scanf( "%" SCNd16 "%" SCNd16, &segments[ i ].first, &segments[ i ].second );

   struct CacheData
   {
      uint16_t mSegmentPos;
      uint16_t mCount;
      uint16_t mPrev;
   };

   std::vector< CacheData > cache;
   cache.reserve( N );
   for( uint16_t i = 0; i < N; ++i )
      cache.push_back( CacheData{ .mSegmentPos = i, .mCount = 1, .mPrev = std::numeric_limits< uint16_t >::max() } );
   std::sort( cache.begin(), cache.end(), [ & ]( CacheData const& a, CacheData const& b )
   {
      return segments[ a.mSegmentPos ].second < segments[ b.mSegmentPos ].second;
   });

   for( uint16_t i = 0; i < cache.size(); ++i )
   {
      auto const& segment = segments[ cache[ i ].mSegmentPos ];
      for( uint16_t j = 0; j < i; ++j )
      {
         auto const& tmp_segment = segments[ cache[ j ].mSegmentPos ];
         if( tmp_segment.first <= segment.first || tmp_segment.second >= segment.second )
            continue;
         if( cache[ i ].mCount < cache[ j ].mCount + 1 )
         {
            cache[ i ].mCount = cache[ j ].mCount + 1;
            cache[ i ].mPrev = j;
         }
      }
   }

   uint16_t result_pos = 0;
   for( uint16_t i = 0; i < cache.size(); ++i )
      if( cache[ result_pos ].mCount < cache[ i ].mCount )
         result_pos = i;

   std::vector< uint16_t > result_segments;
   while( result_pos != std::numeric_limits< uint16_t >::max() )
   {
      result_segments.push_back( cache[ result_pos ].mSegmentPos );
      result_pos = cache[ result_pos ].mPrev;
   }

   std::printf( "%" PRIu16 "\n", static_cast< uint16_t >( result_segments.size() ) );
   for( auto it = result_segments.rbegin(); it != result_segments.rend(); ++it )
      std::printf( "%" PRIu16 " ", (*it)+1 );

   std::printf( "\n" );

   return 0;
}
