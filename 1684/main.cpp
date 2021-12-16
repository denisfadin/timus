#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
#include <string_view>

std::vector< uint32_t > CalcPrefix( std::string const& s )
{
	uint32_t n = static_cast< uint32_t >( s.size() );
	std::vector< uint32_t > pi( n );
    pi[ 0 ] = 0;
	for( uint32_t i = 1; i < n; ++i )
    {
		uint32_t j = pi[ i-1 ];
		while( j > 0 && s[ i ] != s[ j ] )
    	   j = pi[ j-1 ];
		if( s[ i ] == s[ j ] )
            ++j;
		pi[ i ] = j;
	}
	return pi;
}

std::vector< std::string_view > Do( std::string const& word, std::string const& jack_word )
{
   std::vector< uint32_t > word_prefix = CalcPrefix( word );

   std::vector< uint32_t > jack_word_poses( jack_word.size(), 0 );
   uint32_t pos = 0;
   uint32_t i = 0;
   while( i < jack_word.size() )
   {
      if( jack_word[ i ] == word[ pos ] )
      {
         jack_word_poses[ i ] = pos;
         ++pos;
         ++i;
      }
      else
      {
         if( pos == 0 )
            return std::vector< std::string_view >();
         else
            pos = word_prefix[ pos - 1 ];
      }
   }

   std::vector< std::string_view > result;

   uint32_t size = 1;
   uint32_t prev_idx = jack_word_poses[ 0 ];
   for( uint32_t i = 1; i < jack_word_poses.size(); ++i )
   {
      if( jack_word_poses[ i ] > prev_idx )
      {
         ++size;
         prev_idx = jack_word_poses[ i ];
      }
      else
      {
         result.push_back( std::string_view( word.c_str(), size - jack_word_poses[ i ] ) );
         prev_idx = jack_word_poses[ i ];
         size = jack_word_poses[ i ] + 1;
      }
   }

   if( size > 0 )
      result.push_back( std::string_view( word.c_str(), size ) );

   return result;
}

int main()
{
   std::string word;
   std::getline( std::cin, word );

   std::string jack_word;
   std::getline( std::cin, jack_word );

   std::vector< std::string_view > result = Do( word, jack_word );
   if( result.empty() )
      std::cout << "Yes" << std::endl;
   else
   {
      std::cout << "No" << std::endl;
      for( auto const& item : result )
         std::cout << item << " ";
      std::cout << std::endl;
   }

   return 0;
}
