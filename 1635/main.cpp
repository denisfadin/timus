#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>
#include <cstring>
#include <string_view>
#include <limits>

uint32_t MakeKey( uint32_t size, uint32_t i, uint32_t j )
{
   return i * (size + 1) + j;
}

std::vector< bool > PalindromesSet( std::string_view str )
{
   std::vector< bool > result( str.size() * ( str.size() + 1 ), false );

   // odd
   {
      for( int32_t indMiddle = 0; indMiddle < str.size(); ++indMiddle )
      {
         int32_t leftBorder = indMiddle - 1, rightBorder = indMiddle + 1;
         while( leftBorder >= 0 && rightBorder < str.size()
                && str[ leftBorder ] == str[ rightBorder ] )
         {
            result[ MakeKey( str.size(), leftBorder, rightBorder - leftBorder + 1 ) ] = true;
            --leftBorder;
            ++rightBorder;
         }
      }
   }

   // even
   {
      for( int32_t indMiddle = 0; indMiddle < str.size(); ++indMiddle )
      {
         int32_t leftBorder = indMiddle, rightBorder = indMiddle + 1;
         while( leftBorder >= 0 && rightBorder < str.size()
                && str[ leftBorder ] == str[ rightBorder ] )
         {
            result[ MakeKey( str.size(), leftBorder, rightBorder - leftBorder + 1 ) ] = true;
            --leftBorder;
            ++rightBorder;
         }
      }
   }

   return result;
}

int main()
{
   std::vector< char > buffer( 4001, 0 );
   std::scanf( "%s", buffer.data() );

   std::string_view name( buffer.data(), std::strlen( buffer.data() ) );

   std::vector< bool > palindromes = PalindromesSet( name );

   struct CacheData
   {
      uint32_t mCount;
      uint32_t mLastLength;
   };

   std::vector< CacheData > cache( name.size() );
   cache[ 0 ].mCount = 1;
   cache[ 0 ].mLastLength = 1;

   for( uint32_t i = 1; i < name.size(); ++i )
   {
      cache[ i ].mCount = cache[ i - 1 ].mCount + 1;
      cache[ i ].mLastLength = 1;

      for( uint32_t j = 1; j <= i; ++j )
      {
         if( !palindromes[ MakeKey( name.size(), i - j, j+1 ) ] )
            continue;

         if( j == i )
         {
            cache[ i ].mCount = 1;
            cache[ i ].mLastLength = j+1;
            continue;
         }

         if( cache[ i ].mCount <= cache[ i-j-1 ].mCount + 1 )
            continue;

         cache[ i ].mCount = cache[ i-j-1 ].mCount + 1;
         cache[ i ].mLastLength = j + 1;
      }
   }

   std::vector< uint32_t > lengths;
   for( int32_t i = name.size() - 1; i >= 0; )
   {
      lengths.push_back( cache[ i ].mLastLength );
      i -= cache[ i ].mLastLength;
   }

   std::printf( "%" PRIu32 "\n", lengths.size() );

   for( uint32_t pos = 0; !lengths.empty(); lengths.pop_back() )
   {
      std::printf( "%.*s ", static_cast< int >( lengths.back() ), name.data() + pos );
      pos += lengths.back();
   }

   return 0;
}
