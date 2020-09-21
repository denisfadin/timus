#include <cinttypes>
#include <iostream>
#include <vector>

class Matrix
{
public:

   Matrix( uint32_t size )
      : mSize( size ),
        mMatrix( static_cast< uint32_t >( mSize * mSize ), 0 )
   {}

   uint32_t Get( uint32_t i, uint32_t j ) const
   {
      i -= 1;
      j -= 1;
      return mMatrix[ i * mSize + j ];
   }

   void Set( uint32_t i, uint32_t j, uint32_t value )
   {
      i -= 1;
      j -= 1;
      mMatrix[ i * mSize + j ] = value;
   }

private:

   uint32_t mSize;
   std::vector< uint32_t > mMatrix;
};

int main()
{
   uint32_t N;
   std::cin >> N;

   Matrix relations( N );

   for( uint32_t i = 1; i <= N; ++i )
      relations.Set( i, i, 1 );

   for( uint32_t i = 1; i <= N; ++i )
   {
      std::vector< uint32_t > kids;
      while( true )
      {
         uint32_t kid;
         std::cin >> kid;
         if( !kid )
            break;
         relations.Set( kid, i, 1 );
         relations.Set( kid, kid, 0 );
      }
   }

   std::vector< uint32_t > to_process;
   for( uint32_t i = 1; i <= N; ++i )
   {
      if( relations.Get( i, i ) == 1 )
         to_process.push_back( i );
   }

   std::vector< uint32_t > result;
   while( !to_process.empty() )
   {
      uint32_t current = to_process.back();
      to_process.pop_back();
      result.push_back( current );

      for( uint32_t i = 1; i <= N; ++i )
      {
         if( i == current )
            continue;
         relations.Set( i, current, 0 );
         bool empty = true;
         for( uint32_t j = 1; j <= N; ++j )
         {
            if( relations.Get( i, j ) == 1 )
            {
               empty = false;
               break;
            }
         }
         if( empty )
         {
            to_process.push_back( i );
            relations.Set( i, i, 1 );
         }
      }
   }

   for( auto const& r : result )
      std::cout << r << " ";
   std::cout << std::endl;

   return 0;
}
