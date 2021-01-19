#include <cstdint>
#include <cstdio>
#include <cinttypes>

int main()
{
   uint32_t A, B;
   std::scanf( "%" SCNu32 "%" SCNu32, &A, &B );

   uint32_t result = 1;

   int32_t last_value;
   std::scanf( "%" SCNd32, &last_value );

   enum class Type
   {
      tUP,
      tUNDEFINED,
      tDOWN,
   } type = Type::tUNDEFINED;

   for( uint32_t i = A + 1; i <= B; ++i )
   {
      int32_t f;
      std::scanf( "%" SCNd32, &f );

      switch( type )
      {
         case Type::tUNDEFINED:
         {
            if( last_value < f )
               type = Type::tUP;
            else if( last_value > f )
               type = Type::tDOWN;

            break;
         }
         case Type::tUP:
         {
            if( last_value > f )
            {
               ++result;
               type = Type::tUNDEFINED;
            }

            break;
         }
         case Type::tDOWN:
         {
            if( last_value < f )
            {
               ++result;
               type = Type::tUNDEFINED;
            }

            break;
         }
      }

      last_value = f;
   }

   std::printf( "%" PRIu32 "\n", result );

   return 0;
}
