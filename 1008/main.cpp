#include <cstdint>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

uint16_t const MAX_N = 10;

void FirstType( uint16_t n )
{
   std::vector< bool > buf( MAX_N*MAX_N, false );

   uint16_t x_min = MAX_N-1, y_min = MAX_N-1; // тут будет самый нижний из самых левых пикселей
   for( uint16_t i = 0; i < n; ++i )
   {
      uint16_t x, y;
      std::cin >> x >> y;
      --x; --y;
      buf[ y*MAX_N + x ] = true;

      if( x_min > x )
      {
         x_min = x;
         y_min = y;
      }
      else if( x_min == x && y_min > y )
      {
         y_min = y;
      }
   }

   std::cout << x_min+1 << " " << y_min+1 << std::endl;

   std::vector< std::pair< uint16_t, uint16_t > > queue;
   queue.emplace_back( x_min, y_min );

   auto process_point = [&]( uint16_t x, uint16_t y, char sym )
   {
      auto p = std::make_pair( x, y );
      if( buf[ y*MAX_N + x ] && std::find( queue.begin(), queue.end(), p ) == queue.end() )
      {
         std::cout << sym;
         queue.emplace_back( std::move( p ) );
      }
   };

   for( uint16_t i = 0; i < queue.size(); ++i )
   {
      auto item = queue[ i ];

      if( item.first < MAX_N-1 )
         process_point( item.first+1, item.second, 'R' );
      if( item.second < MAX_N-1 )
         process_point( item.first, item.second+1, 'T' );
      if( item.first > 0 )
         process_point( item.first-1, item.second, 'L' );
      if( item.second > 0 )
         process_point( item.first, item.second-1, 'B' );

      std::cout << ( i+1 == queue.size() ? "." : "," ) << std::endl;
   }
}

void SecondType( uint16_t x_min, uint16_t y_min )
{
   --x_min; --y_min;

   std::vector< bool > buf( MAX_N*MAX_N, false );
   std::vector< std::pair< uint16_t, uint16_t > > queue;
   auto process_point = [&]( uint16_t x, uint16_t y )
   {
      auto p = std::make_pair( x, y );
      buf[ y*MAX_N + x ] = true;
      queue.emplace_back( std::move( p ) );
   };

   process_point( x_min, y_min );

   for( uint16_t i = 0; i < queue.size(); ++i )
   {
      auto item = queue[ i ];
      char sym;
      std::cin >> sym;
      while( sym != ',' && sym != '.' )
      {
         switch( sym )
         {
            case 'R':
               process_point( item.first+1, item.second );
               break;
            case 'T':
               process_point( item.first, item.second+1 );
               break;
            case 'L':
               process_point( item.first-1, item.second );
               break;
            case 'B':
               process_point( item.first, item.second-1 );
               break;
         }
         std::cin >> sym;
      }
   }

   std::cout << queue.size() << std::endl;

   for( uint16_t i = 0; i < MAX_N; ++i )
      for( uint16_t j = 0; j < MAX_N; ++j )
         if( buf[ j*MAX_N + i ] )
         {
            std::cout << i+1 << " " << j+1 << std::endl;
         }
}

int main()
{
   std::string s;
   std::getline( std::cin, s );

   std::stringstream ss( s );

   if( s.find( ' ' ) != std::string::npos )
   {
      uint16_t x_min, y_min;
      ss >> x_min >> y_min;
      SecondType( x_min, y_min );
   }
   else
   {
      uint16_t n;
      ss >> n;
      FirstType( n );
   }

   return 0;
}
