#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <list>
#include <algorithm>

// Переводит слово в номер по заданной таблице соответствия
std::string Word2Number( std::string const& word );

std::list< size_t > find_min( size_t pos, size_t end_pos, std::unordered_map< size_t, std::list< std::pair< size_t, size_t > > > const& map, std::vector< std::string > const& words )
{
   std::list< size_t > result;

   auto it = map.find( pos );
   if( it != map.end() )
   {
      for( std::pair< size_t, size_t > const& p : it->second )
      {
         std::string const& word = words[p.first];
         if( pos + p.second == end_pos )
         {
            result.clear();
            result.push_back( p.first );
            break;
         }
         else
         {
            auto res = find_min( pos + p.second, end_pos, map, words );
            if( res.size() != 0 && ( result.size() == 0 || result.size()-1 > res.size() ) )
            {
               result.clear();
               result.push_back( p.first );
               result.splice( result.end(), res );
            }
         }
      }
   }
   return result;
}

int main()
{
   std::string number;
   while( true )
   {
      std::cin >> number;
      if( number == "-1" )
         break;

      //std::cout << number << std::endl;

      size_t cnt = 0;
      std::cin >> cnt;

      //std::cout << cnt << std::endl;

      std::vector< std::string > words;
      words.resize( cnt );

      std::unordered_map< size_t, std::list< std::pair< size_t, size_t > > > map;

      for( size_t i = 0; i < cnt; ++i )
      {
         std::string& word = words[i];
         std::cin >> word;
         std::string word_number = Word2Number( word );

         //std::cout << word << " -> " << word_number << " (";
         size_t pos = number.find( word_number );
         while( pos != std::string::npos )
         {
            //std::cout << pos << ",";
            std::list< std::pair< size_t, size_t > >& l = map[ pos ];
            if( std::find_if( l.begin(), l.end(), [&word_number]( std::pair< size_t, size_t > const& p ) -> bool { return p.second == word_number.size(); }) == l.end() )
            {
               l.push_back( std::make_pair( i, word_number.size() ) );
            }

            pos = number.find( word_number, pos + word_number.size() );
         }
         //std::cout << ")" << std::endl;
      }

      std::list< size_t > result = find_min( 0, number.size(), map, words );
      if( result.size() == 0 )
         std::cout << "No solution." << std::endl;
      else
      {
         for( size_t i : result )
            std::cout << words[i] << " ";
         std::cout << std::endl;
      }
   }
   return 0;
}

char Char2Digit( char c )
{
   switch( c )
   {
      case 'i':
      case 'j':
         return '1';
      case 'a':
      case 'b':
      case 'c':
         return '2';
      case 'd':
      case 'e':
      case 'f':
         return '3';
      case 'g':
      case 'h':
         return '4';
      case 'k':
      case 'l':
         return '5';
      case 'm':
      case 'n':
         return '6';
      case 'p':
      case 'r':
      case 's':
         return '7';
      case 't':
      case 'u':
      case 'v':
         return '8';
      case 'w':
      case 'x':
      case 'y':
         return '9';
      case 'o':
      case 'q':
      case 'z':
         return '0';
   }
   return '?';
}

std::string Word2Number( std::string const& word )
{
   std::string number;
   number.resize( word.size() );
   for( size_t i = 0; i < word.size(); ++i )
      number[i] = Char2Digit( word[i] );
   return number;
}
