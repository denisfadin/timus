#include <cstdint>
#include <iostream>
#include <string>
#include <cctype>

int main()
{
   std::string line;
   while( std::getline( std::cin, line ) )
   {
      uint16_t left_pos = 0;
      for( uint16_t i = 0; i <= line.size(); ++i )
      {
         if( std::isalpha( line[ i ] ) )
            continue;
         else if( left_pos < i )
         {
            uint16_t right_pos = i - 1;
            while( left_pos < right_pos )
               std::swap( line[ left_pos++ ], line[ right_pos-- ] );
         }
         left_pos = i + 1;
      }
      std::printf( "%.*s\n", static_cast< int >( line.size() ), line.data() );
   }
   return 0;
}
