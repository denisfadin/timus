#include <iostream>
#include <stdint.h>
#include <vector>

class Matrix
{
   public:

      Matrix( int16_t n_, int16_t m_ )
         : n( n_ ), m( m_ ), buf( n * m, false )
      {
      }

      int16_t getN() const
      {
         return n;
      }

      int16_t getM() const
      {
         return m;
      }

      bool get( int16_t i, int16_t j ) const
      {
         if( i >= n || j >= m )
            return false;
         return buf[ i*m + j ];
      }

      void set( bool val, int16_t i, int16_t j )
      {
         buf[ i*m + j ] = val;
      }

   private:

      int16_t n;
      int16_t m;
      std::vector< bool > buf;
};

// Работа с прямоугольниками на матрице
class Rectangles
{
public:

   Rectangles( Matrix const& matrix )
      : n( matrix.getN() ),
        m( matrix.getM() ),
        buf( n * m, 0 )
   {
      for( int16_t i = 0; i < n; ++i )
         for( int16_t j = 0; j < m; ++j )
         {
            buf[ i*m + j ] = getSum( i-1, j ) + getSum( i, j-1 ) - getSum( i-1, j-1 ) + ( matrix.get( i, j ) ? 1 : 0 );
         }
   }

   // Получить сумму единиц на прямоугольнике (0,0) - (i,j)
   int32_t getSum( int16_t i, int16_t j ) const
   {
      if( i < 0 || j < 0 )
         return 0;
      i = std::min( i, (int16_t)(n-1) );
      j = std::min( j, (int16_t)(m-1) );
      return buf[ i*m + j ];
   }

   // Получить сумму единиц на прямоугольнике (xi,xj) - (yi,yj)
   int32_t getSum( int16_t xi, int16_t xj, int16_t yi, int16_t yj ) const
   {
      return getSum( yi, yj ) - getSum( xi-1, yj ) - getSum( yi, xj-1 ) + getSum( xi-1, xj-1 );
   }

private:

   int16_t n;
   int16_t m;
   std::vector< int32_t > buf;
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

   Matrix matrix( n, m );

   std::string s;
   s.reserve( m );
   for( int16_t i = 0; i < n; ++i )
   {
      std::cin >> s;
      for( int16_t j = 0; j < m; ++j )
         matrix.set( s[j] == '1', i, j );
   }

   Rectangles rects( matrix );

   int32_t result = n * m;

   std::vector< int16_t > pnums = GetPrimeNumbers( std::max( n, m ) );
   for( auto const& num : pnums )
   {
      int32_t res = 0;

      for( int16_t i = 0; i < n; i += num )
         for( int16_t j = 0; j < m; j += num )
         {
            int32_t cnt = rects.getSum( i, j, i+num-1, j+num-1 );
            res += std::min( cnt, num*num - cnt );
         }

      result = std::min( result, res );
   }

   std::cout << result << std::endl;
}
