#include <iostream>
#include <string>
#include <cinttypes>
#include <stdexcept>
#include <unordered_map>
#include <unordered_set>
#include <vector>

char Letter2Digit( char letter )
{
   switch( letter )
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
   throw std::invalid_argument( "Invalid argument of Letter2Digit" );
}

std::string Word2Number( std::string const& word )
{
   std::string result;
   result.reserve( word.size() );
   for( char sym : word )
      result.push_back( Letter2Digit( sym ) );
   return result;
}

int main()
{
   while( true )
   {
      std::string number;
      std::cin >> number;

      if( number == "-1" )
         break;

      uint32_t words_count;
      std::cin >> words_count;

      struct Edge
      {
         size_t mTo;
         std::string mWord;
      };
      std::unordered_map< size_t, std::vector< Edge > > edges;

      for( uint32_t i = 0; i < words_count; ++i )
      {
         std::string word;
         std::cin >> word;

         std::string word_number = Word2Number( word );

         size_t pos = 0;
         while( true )
         {
            pos = number.find( word_number, pos );
            if( pos == std::string::npos )
               break;

            std::vector< Edge >& e = edges[ pos ];
            e.push_back( Edge{ .mTo = pos + word.size(), .mWord = word } );

            ++pos;
            if( pos >= number.size() )
               break;
         }
      }

      std::vector< size_t > to_process;
      to_process.push_back( 0 );
      std::unordered_set< size_t > processed;

      std::unordered_map< size_t, std::vector< const char* > > points;
      while( !to_process.empty() )
      {
         size_t p = to_process.back();
         to_process.pop_back();
         if( processed.find( p ) != processed.end() )
            continue;
         processed.insert( p );

         std::vector< const char* > const& pos_words = points[ p ];

         auto it_edges = edges.find( p );
         if( it_edges == edges.end() )
            continue;

         for( auto const& edge : it_edges->second )
         {
            std::vector< const char* >& words = points[ edge.mTo ];
            if( words.empty() || ( words.size() > pos_words.size() + 1 ) )
            {
               words = pos_words;
               words.push_back( edge.mWord.c_str() );
            }
            to_process.push_back( edge.mTo );
         }
      }

      auto it = points.find( number.size() );
      if( it == points.end() )
      {
         std::cout << "No solution." << std::endl;
      }
      else
      {
         for( const char* word : it->second )
            std::cout << word << " ";
         std::cout << std::endl;
      }
   }

   return 0;
}
