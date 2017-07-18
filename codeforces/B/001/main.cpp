#include <iostream>
#include <cstdint>
#include <string>

int main()
{
   int32_t N;
   std::cin >> N;

   std::string s;

   for( int32_t i = 0; i < N; ++i )
   {
      std::cin >> s;

      if( s.at( 0 ) == 'R' && s.at( 1 ) >= '1' && s.at( 1 ) <= '9' && s.find( 'C' ) != std::string::npos )
      {
         // R1C1
         //std::cout << "RXCY" << std::endl;
      }
      else
      {
         // A1
         size_t pos = 0;
         for( ; s.at( pos ) >= 'A' && s.at( pos ) <= 'Z'; ++pos )
            ;
         std::cout << 'R' << ( s.c_str() + pos );

         int32_t y = 0;
         int32_t d = 1;

         while( true )
         {
            --pos;
            y += ( s.at( pos ) - 'A' + 1 ) * d;

            if( pos == 0 )
               break;

            d *= 26;
         }
         std::cout << "C" << y << std::endl;
      }
   }

   return 0;
}
