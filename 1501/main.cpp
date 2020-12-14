#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>
#include <cstdlib>
#include <unordered_map>

class Cache
{
public:

   void Set( uint64_t pile1_idx, uint64_t pile2_idx, int16_t sum,
             std::vector< bool > const& value )
   {
      uint64_t key = static_cast< uint64_t >( sum + 1 );
      key += ( pile1_idx << 32 );
      key += ( pile2_idx << 48 );

      mCache[ key ] = value;
   }

   std::vector< bool > const* Get( uint64_t pile1_idx, uint64_t pile2_idx, int16_t sum )
   {
      uint64_t key = static_cast< uint64_t >( sum + 1 );
      key += ( pile1_idx << 32 );
      key += ( pile2_idx << 48 );

      auto it = mCache.find( key );
      if( it != mCache.end() )
         return &(it->second);

      return nullptr;
   }

private:

   std::unordered_map< uint64_t, std::vector< bool > > mCache;
};

std::vector< bool > Do( std::vector< bool > const& pile1, uint16_t pile1_idx,
                        std::vector< bool > const& pile2, uint16_t pile2_idx,
                        int16_t sum )
{
   static Cache cache;

   {
      std::vector< bool > const* cache_result = cache.Get( pile1_idx, pile2_idx, sum );
      if( cache_result )
         return *cache_result;
   }

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
            cache.Set( pile1_idx, pile2_idx, sum, result );
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
            cache.Set( pile1_idx, pile2_idx, sum, result );
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
            cache.Set( pile1_idx, pile2_idx, sum, result );
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
            cache.Set( pile1_idx, pile2_idx, sum, result );
            return result;
         }
      }
   }

   cache.Set( pile1_idx, pile2_idx, sum, std::vector< bool >{} );
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
