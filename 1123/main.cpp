#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <cstring>
#include <vector>

int main()
{
   std::vector< char > buffer( 2001, 0 );
   std::scanf( "%s", buffer.data() );

   uint16_t size = std::strlen( buffer.data() );
   if( size > 1 )
   {
      if( size % 2 )
      {
         uint16_t i1 = size / 2 - 1;
         uint16_t i2 = i1 + 2;
         if( buffer[ i1 ] < buffer[ i2 ] )
         {
            if( buffer[ i1 + 1 ] != '9' )
               buffer[ i1 + 1 ] += 1;
            else
            {
               buffer[ i1 ] += 1;
               buffer[ i1 + 1 ] = '0';
            }
         }
         for( ; i2 < size; ++i2, --i1 )
            buffer[ i2 ] = buffer[ i1 ];
      }
      else
      {
         uint16_t i1 = size / 2 - 1;
         uint16_t i2 = i1 + 1;
         if( buffer[ i1 ] < buffer[ i2 ] )
            buffer[ i1 ] += 1;
         for( ; i2 < size; ++i2, --i1 )
            buffer[ i2 ] = buffer[ i1 ];
      }
   }

   std::printf( "%.*s\n", static_cast< int >( size ), buffer.data() );

   return 0;
}
