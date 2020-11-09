#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>
#include <limits>

template< typename T >
inline T add_safe( T a, T b )
{
   if( std::numeric_limits< T >::max() - a < b )
      return std::numeric_limits< T >::max();
   else
      return a + b;
}

int main()
{
   uint_fast16_t M, N;
   std::scanf( "%" SCNuFAST16 "%" SCNuFAST16, &M, &N );

   auto const ROOMS_COUNT = M*N;

   std::vector< uint32_t > fees( ROOMS_COUNT + 1, 0 );
   for( uint_fast16_t i = 1; i <= ROOMS_COUNT; ++i )
      std::scanf( "%" SCNu32, &fees[ i ] );

   std::vector< uint16_t > rooms( ROOMS_COUNT + 1, 0 );

   for( uint_fast16_t fl = 1; fl < M; ++fl )
   {
      auto const start = fl * N;
      std::vector< uint32_t > floor_fees( fees.begin() + start, fees.begin() + start + 1 + N );

      for( uint_fast16_t r = 1; r <= N; ++r )
      {
         auto const curr_room = start + r;

         fees[ curr_room ] = add_safe( floor_fees[ r ], fees[ curr_room - N ] );
         rooms[ curr_room ] = curr_room - N;
      }

      for( uint_fast16_t r = 2; r <= N; ++r )
      {
         auto const curr_room = start + r;

         auto fee = add_safe( floor_fees[ r ], fees[ curr_room - 1 ] );
         if( fee < fees[ curr_room ] )
         {
            fees[ curr_room ] = fee;
            rooms[ curr_room ] = curr_room - 1;
         }
      }

      for( uint_fast16_t r = N - 1; r >= 1; --r )
      {
         auto const curr_room = start + r;

         auto fee = add_safe( floor_fees[ r ], fees[ curr_room + 1 ] );
         if( fee < fees[ curr_room ] )
         {
            fees[ curr_room ] = fee;
            rooms[ curr_room ] = curr_room + 1;
         }
      }
   }

   auto last_floor = ( M - 1 ) * N;
   auto room = last_floor + 1;
   auto min_fee = fees[ room ];

   for( uint_fast16_t r = 2; r <= N; ++r )
   {
      auto curr_r = last_floor + r;
      if( min_fee > fees[ curr_r ] )
      {
         min_fee = fees[ curr_r ];
         room = curr_r;
      }
   }

   std::vector< uint16_t > result;
   result.reserve( M );
   while( room )
   {
      result.push_back( room );
      room = rooms[ room ];
   }

   for( auto it = result.rbegin(); it != result.rend(); ++it )
      std::printf( "%" PRIu16 " ", static_cast< uint16_t > ( *it % N ? *it % N : N ) );

   std::printf( "\n" );

   return 0;
}
