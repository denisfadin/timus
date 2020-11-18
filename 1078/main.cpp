#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>
#include <utility>
#include <algorithm>

int main()
{
   uint16_t N;
   std::scanf( "%" SCNu16, &N );

   using SegmentT = std::pair< int16_t, int16_t >;

   std::vector< SegmentT > segments( N );
   std::vector< uint16_t > segments_poses( N );
   for( uint16_t i = 0; i < N; ++i )
   {
      std::scanf( "%" SCNd16 "%" SCNd16, &segments[ i ].first, &segments[ i ].second );
      segments_poses[ i ] = i;
   }

   std::sort( segments_poses.begin(), segments_poses.end(), [ & ]( uint16_t a, uint16_t b )
   {
      return segments[ a ].second < segments[ b ].second;
   });

   struct CacheData
   {
      uint16_t mSegmentPos;
      uint16_t mCount;
      uint16_t mPrev;
   };

   std::vector< CacheData > cache;

   for( auto segment_pos : segments_poses )
   {
      auto const& segment = segments[ segment_pos ];

      CacheData data;
      data.mSegmentPos = segment_pos;
      data.mCount = 1;
      data.mPrev = cache.size();

      for( uint16_t i = 0; i < cache.size(); ++i )
      {
         auto const& tmp_segment = segments[ cache[ i ].mSegmentPos ];
         if( tmp_segment.first <= segment.first || tmp_segment.second >= segment.second )
            continue;
         if( data.mCount < cache[ i ].mCount + 1 )
         {
            data.mCount = cache[ i ].mCount + 1;
            data.mPrev = i;
         }
      }

      cache.push_back( std::move( data ) );
   }

   uint16_t result_pos = 0;
   for( uint16_t i = 0; i < cache.size(); ++i )
      if( cache[ result_pos ].mCount < cache[ i ].mCount )
         result_pos = i;

   std::vector< uint16_t > result_segments;
   while( true )
   {
      result_segments.push_back( cache[ result_pos ].mSegmentPos );
      if( result_pos == cache[ result_pos ].mPrev )
         break;
      result_pos = cache[ result_pos ].mPrev;
   }

   std::printf( "%" PRIu16 "\n", static_cast< uint16_t >( result_segments.size() ) );
   for( auto it = result_segments.rbegin(); it != result_segments.rend(); ++it )
      std::printf( "%" PRIu16 " ", (*it)+1 );

   std::printf( "\n" );

   return 0;
}
