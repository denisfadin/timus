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

   uint16_t i1 = size / 2;
   uint16_t i2 = i1;

   if( size % 2 == 0 )
      i1 -= 1;

   while( i2 < size )
   {
      if( buffer[ i1 ] != buffer[ i2 ] )
      {
         if( buffer[ i1 ] < buffer[ i2 ] )
         {
            uint16_t i = i2 - 1;
            while( true )
            {
               if( buffer[ i ] != '9' )
               {
                  buffer[ i ] += 1;
                  break;
               }
               else
               {
                  buffer[ i ] = '0';
                  --i;
               }
            }

            i1 = i2 = size / 2;
            if( size % 2 == 0 )
               i1 -= 1;
         }
         break;
      }

      i1 -= 1;
      i2 += 1;
   }

   while( i2 < size )
   {
      buffer[ i2 ] = buffer[ i1 ];
      i1 -= 1;
      i2 += 1;
   }

   std::printf( "%.*s\n", static_cast< int >( size ), buffer.data() );

   return 0;
}
