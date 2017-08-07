#include <iostream>
#include <stdint.h>
#include <vector>

template< typename T >
class Matrix
{
   public:

      Matrix( int16_t n_, int16_t m_, T const& val )
         : n( n_ ), m( m_ ), buf( n * m, val )
      {
      }

      T get( int16_t i, int16_t j ) const
      {
         if( i >= n || j >= m )
            return T( 0 );
         return buf[ i*m + j ];
      }

      void set( T const& val, int16_t i, int16_t j )
      {
         buf[ i*m + j ] = val;
      }

   private:

      int16_t n;
      int16_t m;
      std::vector< T > buf;
};

// Формирует массив простых чисел не больших n
std::vector< int16_t > GetPrimeNumbers( int16_t n )
{
   std::vector< int16_t > result;

   std::vector< int16_t > buf( n+1, 1 );
   for( int16_t k = 2; k <= n; ++k )
      if( buf[k] == 1 )
      {
         for( int32_t l = k*k; l <= n; l += k )
            buf[l] = 0;

         result.push_back( k );
      }
   return result;
}

int main()
{
   int16_t n, m;
   std::cin >> n >> m;

   Matrix< bool > matrix( n, m, false );

   std::string s;
   s.reserve( m );
   for( int16_t i = 0; i < n; ++i )
   {
      std::cin >> s;
      for( int16_t j = 0; j < m; ++j )
         matrix.set( s[j] == '1', i, j );
   }

   /*for( int16_t i = 0; i < std::max( n, m ); ++i )
   {
      for( int16_t j = 0; j < std::max( n, m ); ++j )
      {
         std::cout << matrix.get( i, j ) ? '1' : '0';
      }
      std::cout << std::endl;
   }*/

   int32_t result = n * m;

   std::vector< int16_t > pnums = GetPrimeNumbers( std::max( n, m ) );
   for( auto const& num : pnums )
   {
      //std::cout << "num: " << num << std::endl;

      int32_t res = 0;

      for( int16_t i = 0; i < n; i += num )
      {
         for( int16_t j = 0; j < m; j += num )
         {
            int32_t cnt1 = 0;
            for( int16_t ii = 0; ii < num; ++ii )
               for( int16_t jj = 0; jj < num; ++jj )
               {
                  if( matrix.get( i+ii, j+jj ) )
                     ++cnt1;
               }
            res += std::min( cnt1, num*num - cnt1 );
         }
      }

      //std::cout << "num res: " << res << std::endl;

      result = std::min( result, res );
   }

   std::cout << result << std::endl;
}
