#include <cstdint>
#include <cstdio>
#include <array>

int main()
{
   std::array< char, 80 > result;
   result.fill( ' ' );
   uint32_t result_pos = 0;

   std::array< char, 1024 > buffer;
   while( true )
   {
      buffer.fill( 0 );
      if( std::fgets( buffer.data(), buffer.size(), stdin ) == nullptr )
         break;

      for( auto const sym : buffer )
      {
         if( sym == '<' )
         {
            if( result_pos > 0 )
               --result_pos;
         }
         else if( sym == '>' )
            ++result_pos;
         else if( sym != '\n' && sym != 0 )
         {
            result[ result_pos ] = sym;
            ++result_pos;
         }

         if( result_pos == result.size() )
            result_pos = 0;
      }
   }

   std::printf( "%.*s\n", result.size(), result.data() );

   return 0;
}
