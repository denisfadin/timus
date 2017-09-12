#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <algorithm>

class Result
{
   enum class OperationType
   {
      Insert,
      GetMin,
      RemoveMin
   };

   using Record = std::pair< OperationType, int32_t >;

   void Log( OperationType op_type, int32_t x )
   {
      log.emplace_back( std::make_pair( op_type, x ) );
   }

public:

   Result( )
   {
      log.reserve( 1000000 );
   }

   void LogInsert( int32_t x )
   {
      Log( OperationType::Insert, x );
   }

   void LogGetMin( int32_t x )
   {
      Log( OperationType::GetMin, x );
   }

   void LogRemoveMin()
   {
      Log( OperationType::RemoveMin, 0 );
   }

   void Write() const
   {
      printf( "%ld\n", log.size() );

      for( auto const& record : log )
      {
         switch( record.first )
         {
            case OperationType::Insert:
               printf( "insert %ld\n", record.second );
               break;
            case OperationType::GetMin:
               printf( "getMin %ld\n", record.second );
               break;
            case OperationType::RemoveMin:
               printf( "removeMin\n", record.second );
               break;
         }
      }
   }

private:

   std::vector< Record > log;
};

int main()
{
   int32_t n;
   scanf( "%ld", &n );

   std::vector< int32_t > heap;
   heap.reserve( 100000 );

   Result result;

   auto comp = []( int32_t const& a, int32_t const& b ) -> bool
   {
      return a > b;
   };

   char operation[10];

   for( int32_t i = 0; i < n; ++i )
   {
      scanf( "%s", operation );

      switch( operation[0] )
      {
         case 'i': // insert
         {
            int32_t x;
            scanf( "%ld", &x );
            heap.emplace_back( x );
            std::push_heap( std::begin( heap ), std::end( heap ), comp );

            result.LogInsert( x );

            break;
         }
         case 'g': // "getMin"
         {
            int32_t x;
            scanf( "%ld", &x );

            bool need_insert = true;
            while( !heap.empty() )
            {
               if( heap[0] == x )
               {
                  need_insert = false;
                  break;
               }

               if( heap[0] > x )
                  break;

               std::pop_heap( std::begin( heap ), std::end( heap ), comp );
               heap.pop_back();

               result.LogRemoveMin();
            }

            if( need_insert )
            {
               heap.emplace_back( x );
               std::push_heap( std::begin( heap ), std::end( heap ), comp );

               result.LogInsert( x );
            }

            result.LogGetMin( x );

            break;
         }
         case 'r': //"removeMin"
         {
            if( heap.empty() )
            {
               heap.emplace_back( 0 );

               result.LogInsert( 0 );
            }
            std::pop_heap( std::begin( heap ), std::end( heap ), comp );
            heap.pop_back();

            result.LogRemoveMin();

            break;
         }
      }
   }

   result.Write();

   return 0;
}
