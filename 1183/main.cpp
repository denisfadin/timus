#include <cstdint>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>

std::vector< char >& get( uint32_t i, uint32_t j )
{
   static std::map< uint32_t, std::vector< char > > DP;
   return DP[ i + ( j << 16 ) ];
}

void append( std::vector< char >& v1, std::vector< char > const& v2 )
{
   v1.insert( v1.end(), v2.begin(), v2.end() );
}

int main()
{
   std::vector< char > source( 101, 0 );
   std::scanf( "%s", source.data() );

   uint32_t const N = std::strlen( source.data() );

   if( N == 0 )
   {
      std::printf( "\n" );
      return 0;
   }

   for( uint32_t i = 0; i < N; ++i )
   {
      auto& data = get( i, 0 );
      if( source[ i ] == '(' || source[ i ] == ')' )
      {
         data.push_back( '(' );
         data.push_back( ')' );
      }
      else
      {
         data.push_back( '[' );
         data.push_back( ']' );
      }
   }

   for( uint32_t i = 0; i + 1 < N; ++i )
   {
      auto& data = get( i, 1 );
      if( source[ i ] == '(' && source[ i + 1 ] == ')' )
      {
         data.push_back( '(' );
         data.push_back( ')' );
      }
      else if( source[ i ] == '[' && source[ i + 1 ] == ']' )
      {
         data.push_back( '[' );
         data.push_back( ']' );
      }
      else
      {
         append( data, get( i, 0 ) );
         append( data, get( i + 1, 0 ) );
      }
   }

   for( uint32_t j = 2; j < N; ++j )
      for( uint32_t i = 0; i + j < N; ++i )
      {
         auto& data = get( i, j );
         append( data, get( i, j - 1 ) );
         append( data, get( i + j, 0 ) );

         if( ( source[ i ] == '(' && source[ i + j ] == ')' ) ||
             ( source[ i ] == '[' && source[ i + j ] == ']' ) )
         {
            if( data.size() > 2 + get( i + 1, j - 2 ).size() )
            {
               data.clear();
               data.push_back( source[ i ] );
               append( data, get( i + 1, j - 2 ) );
               data.push_back( source[ i + j ] );
            }
         }
         else
         {
            if( data.size() > 2 + get( i + 1, j - 1 ).size() )
            {
               data.clear();
               if( source[ i ] == '(' || source[ i ] == ')' )
               {
                  data.push_back( '(' );
                  data.push_back( ')' );
               }
               else
               {
                  data.push_back( '[' );
                  data.push_back( ']' );
               }
               append( data, get( i + 1, j - 1 ) );
            }

            if( data.size() > 2 + get( i, j - 1 ).size() )
            {
               data.clear();
               append( data, get( i, j - 1 ) );
               if( source[ i + j ] == '(' || source[ i + j ] == ')' )
               {
                  data.push_back( '(' );
                  data.push_back( ')' );
               }
               else
               {
                  data.push_back( '[' );
                  data.push_back( ']' );
               }
            }
         }

         if( source[ i ] == '(' || source[ i ] == '[' )
         {
            char sym = ( source[ i ] == '(' ? ')' : ']' );

            for( uint32_t k = 1; k < j; ++k )
            {
               if( source[ i + k ] != sym )
                  continue;

               uint32_t new_size = 2;
               if( k > 1 )
                  new_size += get( i + 1, k - 2 ).size();
               new_size += get( i + k + 1, j - k - 1 ).size();

               if( data.size() > new_size )
               {
                  data.clear();
                  data.push_back( source[ i ] );
                  if( k > 1 )
                     append( data, get( i + 1, k - 2 ) );
                  data.push_back( sym );
                  append( data, get( i + k + 1, j - k - 1 ) );
               }
            }
         }
      }

   auto const& result = get( 0, N - 1 );
   for( auto const sym : result )
      std::putchar( sym );
   std::putchar( '\n' );

   return 0;
}
