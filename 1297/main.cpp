#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <string_view>
#include <cstring>
#include <vector>

int main()
{
   std::vector< char > buffer( 1001, 0 );
   std::scanf( "%s", buffer.data() );

   std::string_view str( buffer.data(), std::strlen( buffer.data() ) );

   std::vector< std::string_view > cache( str.size() + 1 );
   if( !str.empty() )
   {
      cache[ 1 ] = str.substr( 0, 1 );

      // odd
      {
         for( int16_t indMiddle = 0; indMiddle < str.size(); ++indMiddle )
         {
            int16_t leftBorder = indMiddle - 1, rightBorder = indMiddle + 1;
            while( leftBorder >= 0 && rightBorder < str.size()
                   && str[ leftBorder ] == str[ rightBorder ] )
            {
               uint16_t size = rightBorder - leftBorder + 1;
               if( cache[ size ].empty() )
                  cache[ size ] = str.substr( leftBorder, size );

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
               uint16_t size = rightBorder - leftBorder + 1;
               if( cache[ size ].empty() )
                  cache[ size ] = str.substr( leftBorder, size );

               --leftBorder;
               ++rightBorder;
            }
         }
      }
   }

   std::string_view result;
   for( uint16_t i = cache.size() - 1; i > 0; --i )
   {
      if( !cache[ i ].empty() )
      {
         result = cache[ i ];
         break;
      }
   }

   std::printf( "%.*s\n", static_cast< int >( result.size() ), result.data() );

   return 0;
}
