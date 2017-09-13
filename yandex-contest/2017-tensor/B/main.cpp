#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

int main()
{
   std::vector< char > bulls;

   for( char sym = '0'; sym <= '9'; ++sym )
   {
      std::cout << sym << sym << sym << sym << std::endl;

      int16_t b, c;
      std::cin >> b >> c;
      if( b == 4 )
         return 0;

      while( b > 0 )
      {
         bulls.push_back( sym );
         --b;
      }

      if( bulls.size() == 4 )
         break;
   }

   std::unordered_set< std::string > lines;

   for( int16_t i1 = 0; i1 < 4; ++i1 )
   {
      for( int16_t i2 = 0; i2 < 4; ++i2 )
      {
         if( i2 == i1 )
            continue;

         for( int16_t i3 = 0; i3 < 4; ++i3 )
         {
            if( i3 == i1 || i3 == i2 )
               continue;

            for( int16_t i4 = 0; i4 < 4; ++i4 )
            {
               if( i4 == i1 || i4 == i2 || i4 == i3 )
                  continue;

               std::string str( { bulls[i1], bulls[i2], bulls[i3], bulls[i4] } );

               if( lines.find( str ) != lines.end() )
                  continue;
               lines.insert( str );

               std::cout << str << std::endl;

               int16_t b, c;
               std::cin >> b >> c;

               if( b == 4 )
                  return 0;
            }
         }
      }
   }

   return 0;
}
