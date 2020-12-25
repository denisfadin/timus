#include <cstdint>
#include <cstdio>
#include <vector>

std::vector< bool > RotateMatrix( std::vector< bool > const& matrix, uint16_t sz )
{
   std::vector< bool > result( matrix.size() );
   for( uint16_t i = 0; i < sz; ++i )
      for( uint16_t j = 0; j < sz; ++j )
         result[ i * sz + j ] = matrix[ i + (sz - j - 1) * sz ];
   return result;
}

int main()
{
   uint16_t const SIZE = 4;

   std::vector< bool > grille( SIZE * SIZE );
   for( uint16_t i = 0; i < grille.size(); ++i )
   {
      char sym;
      std::scanf( " %c", &sym );
      grille[ i ] = ( sym == 'X' );
   }

   std::vector< char > ciphered_password( grille.size() );
   for( uint16_t i = 0; i < ciphered_password.size(); ++i )
      std::scanf( " %c", &ciphered_password[ i ] );

   for( uint16_t i = 0; i < 4; ++i )
   {
      for( uint16_t j = 0; j < grille.size(); ++j )
         if( grille[ j ] )
            std::printf( "%c", ciphered_password[ j ] );
      grille = RotateMatrix( grille, SIZE );
   }

   std::printf( "\n" );

   return 0;
}
