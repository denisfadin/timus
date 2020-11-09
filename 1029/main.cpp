#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>
#include <limits>

inline uint32_t add_safe( uint32_t a, uint32_t b )
{
   if( std::numeric_limits< uint32_t >::max() - a < b )
      return std::numeric_limits< uint32_t >::max();
   else
      return a + b;
}

int main()
{
   uint32_t M, N;
   std::scanf( "%" SCNu32 "%" SCNu32, &M, &N );

   uint32_t const ROOMS_COUNT = M*N;

   std::vector< uint32_t > fees( ROOMS_COUNT + 1, 0 );
   for( uint32_t i = 1; i <= ROOMS_COUNT; ++i )
      std::scanf( "%" SCNu32, &fees[ i ] );

   std::vector< uint32_t > rooms( ROOMS_COUNT + 1, 0 );

   for( uint32_t fl = 1; fl < M; ++fl )
   {
      auto const start = fl * N;
      std::vector< uint32_t > floor_fees( fees.begin() + start, fees.begin() + start + 1 + N );

      for( uint32_t r = 1; r <= N; ++r )
      {
         auto const curr_room = start + r;

         fees[ curr_room ] = add_safe( floor_fees[ r ], fees[ curr_room - N ] );;
         rooms[ curr_room ] = curr_room - N;
      }

      for( uint32_t r = 2; r <= N; ++r )
      {
         auto const curr_room = start + r;

         auto fee = add_safe( floor_fees[ r ], fees[ curr_room - 1 ] );
         if( fee < fees[ curr_room ] )
         {
            fees[ curr_room ] = fee;
            rooms[ curr_room ] = curr_room - 1;
         }
      }

      for( uint32_t r = N - 1; r >= 1; --r )
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

   // for( uint32_t i = 1; i <= ROOMS_COUNT; ++i )
   // {
   //    std::printf( "%" PRIu32 " ", fees[ i ] );
   //    if( i % N == 0 )
   //       std::printf( "\n" );
   // }
   // std::printf( "\n" );

   uint32_t last_floor = ( M - 1 ) * N;
   uint32_t room = last_floor + 1;
   uint32_t min_fee = fees[ room ];

   for( uint32_t r = 2; r <= N; ++r )
   {
      auto curr_r = last_floor + r;
      if( min_fee > fees[ curr_r ] )
      {
         min_fee = fees[ curr_r ];
         room = curr_r;
      }
   }

   std::vector< uint32_t > result;
   result.reserve( M );
   while( room )
   {
      result.push_back( room );
      room = rooms[ room ];
   }

   for( auto it = result.rbegin(); it != result.rend(); ++it )
      std::printf( "%" PRIu32 " ", *it % N ? *it % N : N );

   std::printf( "\n" );

   return 0;
}
