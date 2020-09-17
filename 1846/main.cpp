#include <iostream>
#include <vector>
#include <unordered_map>

long NOD( long a, long b )
{
   if( a == 0 )
      return b;
   else if( b == 0 )
      return a;

   long nod = 1;

   while( true )
   {
      if( a == b )
         return nod*a;
      else if( a == 1 || b == 1 )
         return nod;

      bool a_even = ( a % 2 == 0 );
      bool b_even = ( b % 2 == 0 );
      if( a_even && b_even )
      {
         nod <<= 1;
         a >>= 1;
         b >>= 1;
      }
      else if( a_even && !b_even )
         a >>= 1;
      else if( !a_even && b_even )
         b >>= 1;
      else if( a > b )
         a = (a-b)>>1;
      else // b > a
         b = (b-a)>>1;
   }
}

int main()
{
   long q;
   std::cin >> q;

   long nMax = 1;
   while( nMax < q )
      nMax <<= 1;

   std::vector< long > tree;
   tree.resize( nMax << 1, 0 );

   std::unordered_multimap< long, long > map;
   map.reserve( q );

   long curr_i = 0;
   for( long i = 0; i < q; ++i )
   {
      char what;
      long a;
      std::cin >> what >> a;

      long pos;
      if( what == '+' )
      {
         pos = nMax + curr_i++;
         tree[pos] = a;
         map.insert( std::make_pair( a, pos ) );
      }
      else
      {
         auto it = map.find( a );
         pos = it->second;
         map.erase( it );
         tree[pos]=0;
      }

      while( pos > 1 )
      {
         pos >>= 1;
         long nod = NOD( tree[pos<<1], tree[(pos<<1)+1] );
         if( tree[pos] == nod )
            break;
         tree[pos] = nod;
      }

      std::cout << ( ( tree[1] > 0 ) ? tree[1] : 1 ) << std::endl;
   }

   return 0;
}
