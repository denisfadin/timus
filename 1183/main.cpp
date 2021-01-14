#include <cstdint>
#include <cstdio>
#include <vector>
#include <list>

int main()
{
   std::list< char > result;
   std::vector< std::list< char >::iterator > add1, add2;

   while( true )
   {
      char sym = std::getchar();
      if( sym == EOF )
         break;
      else if( sym == '[' )
      {
         result.push_back( '[' );
         result.push_back( ']' );
         add1.push_back( --result.end() );
      }
      else if( sym == '(' )
      {
         result.push_back( '(' );
         result.push_back( ')' );
         add2.push_back( --result.end() );
      }
      else if( sym == ']' )
      {
         if( !add1.empty() )
         {
            result.erase( add1.back() );
            add1.pop_back();
            result.push_back( ']' );
         }
         else
         {
            result.push_back( '[' );
            result.push_back( ']' );
         }
      }
      else if( sym == ')' )
      {
         if( !add2.empty() )
         {
            result.erase( add2.back() );
            add2.pop_back();
            result.push_back( ')' );
         }
         else
         {
            result.push_back( '(' );
            result.push_back( ')' );
         }
      }
   }

   for( auto const sym : result )
      std::putchar( sym );
   std::putchar( '\n' );

   return 0;
}
