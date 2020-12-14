#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>
#include <cstdlib>

std::vector< bool > Do( std::vector< bool > const& pile1, uint16_t pile1_idx,
                        std::vector< bool > const& pile2, uint16_t pile2_idx,
                        int16_t sum )
{
   if( ( pile1_idx == pile1.size() && pile2_idx + 1 == pile2.size() ) ||
       ( pile1_idx + 1 == pile1.size() && pile2_idx == pile2.size() ) )
   {
      // осталось извлечь последний элемент
      if( pile1_idx + 1 == pile1.size() )
      {
         int16_t a = pile1[ pile1_idx ] ? 1 : -1;
         if( std::abs( sum + a ) <= 1 )
         {
            std::vector< bool > result;
            result.reserve( pile1.size() + pile2.size() );

            result.push_back( false );
            return result;
         }
         return std::vector< bool >{};
      }
      else
      {
         int16_t a = pile2[ pile2_idx ] ? 1 : -1;
         if( std::abs( sum + a ) <= 1 )
         {
            std::vector< bool > result;
            result.reserve( pile1.size() + pile2.size() );

            result.push_back( true );
            return result;
         }
         return std::vector< bool >{};
      }
   }

   if( pile1_idx < pile1.size() )
   {
      // в первой стопке еще есть элементы
      int16_t a = pile1[ pile1_idx ] ? 1 : -1;
      if( std::abs( sum + a ) <= 1 )
      {
         std::vector< bool > result = Do( pile1, pile1_idx + 1,
                                          pile2, pile2_idx,
                                          sum + a );
         if( !result.empty() )
         {
            result.push_back( false );
            return result;
         }
      }
   }

   if( pile2_idx < pile2.size() )
   {
      // в первой стопке еще есть элементы
      int16_t a = pile2[ pile2_idx ] ? 1 : -1;
      if( std::abs( sum + a ) <= 1 )
      {
         std::vector< bool > result = Do( pile1, pile1_idx,
                                          pile2, pile2_idx + 1,
                                          sum + a );
         if( !result.empty() )
         {
            result.push_back( true );
            return result;
         }
      }
   }

   return std::vector< bool >{};
}

std::vector< bool > Do( std::vector< bool > const& pile1, std::vector< bool > const& pile2 )
{
   {
      int16_t a = pile1[ 0 ] ? 1 : -1;
      std::vector< bool > result = Do( pile1, 1, pile2, 0, a );
      if( !result.empty() )
      {
         result.push_back( false );
         return result;
      }
   }

   {
      int16_t a = pile2[ 0 ] ? 1 : -1;
      std::vector< bool > result = Do( pile1, 0, pile2, 1, a );
      if( !result.empty() )
      {
         result.push_back( true );
         return result;
      }
   }

   return std::vector< bool >{};
}

int main()
{
   uint16_t N;
   std::scanf( "%" SCNu16, &N );

   auto read_pile = [ & ]( std::vector< bool >& pile )
   {
      char sym;
      for( uint16_t i = 0; i < N; ++i )
      {
         std::scanf( " %c", &sym );
         pile[ i ] = ( sym == '1' );
      }
   };

   std::vector< bool > pile1( N );
   read_pile( pile1 );

   std::vector< bool > pile2( N );
   read_pile( pile2 );

   std::vector< bool > result = Do( pile1, pile2 );
   if( result.empty() )
      std::printf( "Impossible\n" );
   else
   {
      for( auto it = result.rbegin(); it != result.rend(); ++it )
         std::printf( "%c", *it ? '2' : '1' );
      std::printf( "\n" );
   }

   return 0;
}
