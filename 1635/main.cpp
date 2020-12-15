#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>
#include <cstring>
#include <string_view>
#include <algorithm>
#include <limits>

std::vector< std::pair< uint16_t, uint16_t > > PalindromesList( std::string_view str )
{
   std::vector< std::pair< uint16_t, uint16_t > > result;

   for( uint16_t i = 0; i < str.size(); ++i )
      result.push_back( std::make_pair( i, i ) );

   // odd
   {
      for( int16_t indMiddle = 0; indMiddle < str.size(); ++indMiddle )
      {
         int16_t leftBorder = indMiddle - 1, rightBorder = indMiddle + 1;
         while( leftBorder >= 0 && rightBorder < str.size()
                && str[ leftBorder ] == str[ rightBorder ] )
         {
            result.push_back( std::make_pair( leftBorder, rightBorder ) );
            --leftBorder;
            ++rightBorder;
         }
      }
   }

   // even
   {
      for( int16_t indMiddle = 0; indMiddle < str.size(); ++indMiddle )
      {
         int16_t leftBorder = indMiddle, rightBorder = indMiddle + 1;
         while( leftBorder >= 0 && rightBorder < str.size()
                && str[ leftBorder ] == str[ rightBorder ] )
         {
            result.push_back( std::make_pair( leftBorder, rightBorder ) );
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

   std::vector< std::pair< uint16_t, uint16_t > > palindromes =
      PalindromesList( name );

   std::sort( palindromes.begin(), palindromes.end(),
      []( std::pair< uint16_t, uint16_t > const& a, std::pair< uint16_t, uint16_t > const& b )
      {
         return a.first < b.first;
      });

   struct CacheData
   {
      uint16_t mCount = std::numeric_limits< uint16_t >::max();
      uint16_t mPos;
   };

   std::vector< CacheData > cache( name.size() );

   // doing algorihtm
   {
      for( uint16_t i = 0; i < palindromes.size(); ++i )
      {
         auto const& pal = palindromes[ i ];

         if( pal.first == 0 )
         {
            CacheData& cache_data = cache[ pal.second ];
            if( cache_data.mCount > 1 )
            {
               cache_data.mCount = 1;
               cache_data.mPos = i;
            }
         }
         else
         {
            CacheData& cache_data_second = cache[ pal.second ];
            CacheData const& cache_data_first = cache[ pal.first - 1 ];
            if( cache_data_second.mCount > cache_data_first.mCount + 1 )
            {
               cache_data_second.mCount = cache_data_first.mCount + 1;
               cache_data_second.mPos = i;
            }
         }
      }
   }

   {

      uint16_t i = name.size() - 1;
      std::printf( "%" PRIu16 "\n", cache[ i ].mCount );

      std::vector< std::string_view > result;
      while( true )
      {
         CacheData const& data = cache[ i ];
         std::pair< uint16_t, uint16_t > const& pal = palindromes[ data.mPos ];
         result.push_back( name.substr( pal.first, pal.second - pal.first + 1 ) );

         if( pal.first > 0 )
            i = pal.first - 1;
         else
            break;
      }

      for( auto it = result.rbegin(); it != result.rend(); ++it )
         std::printf( "%.*s ", static_cast< int >( it->size() ), it->data() );
      std::printf( "\n" );
   }

   return 0;
}
