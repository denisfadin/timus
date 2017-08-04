#include <iostream>
#include <stdint.h>
#include <string>

bool test( int16_t n, int16_t m, std::string const& s1 )
{
   if( !(n%3) )
   {
      int32_t size = (n / 3)*m;

      bool res = ( s1[0] != s1[size] && s1[size] != s1[size*2] && s1[0] != s1[size*2] );

      for( int16_t i = 1; res && i < size; ++i )
         if( s1[0] != s1[i] )
            res = false;
      for( int16_t i = size+1; res && i < size*2; ++i )
         if( s1[size] != s1[i] )
            res = false;
      for( int16_t i = size*2+1; res && i < size*3; ++i )
         if( s1[size*2] != s1[i] )
            res = false;

      return res;
   }

   return false;
}

int main()
{
   int16_t n, m;
   std::cin >> n >> m;

   std::string s1;
   for( int16_t i = 0; i < n; ++i )
   {
      std::string s;
      std::cin >> s;
      s1.append( s );
   }

   bool result = test( n, m, s1 );

   if( !result && !(m%3) )
   {
      std::string s2;
      s2.resize( s1.size() );
      for( int16_t i = 0; i < n; ++i )
         for( int16_t j = 0; j < m; ++j )
            s2[ i + n*j ] = s1[ i*m + j ];

      result = test( m, n, s2 );
   }

   std::cout << ( result ? "YES" : "NO" ) << std::endl;

   return 0;
}
