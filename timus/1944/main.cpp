#include <iostream>
#include <string>
#include <iterator>

int main()
{
   int N = 0;
   std::cin >> N;

   int const max = 100;
   int const size = max + 1 + max;

   std::string buf( size * size, '.' );

   int min_x = 0+max, max_x = 0+max, min_y = 0+max, max_y = 0+max;
   for( int i = 0; i < N; ++i )
   {
      int x, y;
      std::cin >> x >> y;
      x += max;
      y += max;

      if( max_x < x )
         max_x = x;
      else if( min_x > x )
         min_x = x;

      if( max_y < y )
         max_y = y;
      else if( min_y > y )
         min_y = y;

      buf[ y * size + x ] = '*';
   }

   // ось x
   for( auto it = buf.begin() + max * size; it != buf.begin() + ( max + 1 ) * size; ++it )
      if( *it != '*' )
         *it = '-';

   for( int j = max_y; j >= min_y; --j )
   {
      // ось y
      {
         char& c = buf.at( j * size + max );
         if( c != '*' )
         {
            if( j == max )
               c = '+';
            else
               c = '|';
         }
      }

      std::copy( buf.begin() + j * size + min_x, buf.begin() + j * size + max_x + 1, std::ostream_iterator<char>( std::cout ) );
      std::cout << std::endl;
   }

   return 0;
}
