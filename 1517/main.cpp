#include <cstdint>
#include <cstdio>
#include <cinttypes>
#include <vector>
#include <cctype>
#include <map>
#include <string_view>

inline char ReadAlpha()
{
   while( true )
   {
      char sym = static_cast< char >( std::getchar() );
      if( !std::isalpha( sym ) )
         continue;
      return sym;
   }
}

std::vector< char > ReadString( uint32_t N )
{
   std::vector< char > str( N );
   for( uint32_t i = 0; i < N; ++i )
      str[ i ] = ReadAlpha();
   return str;
}

class SA
{
public:

   SA( std::vector< char > const& str )
      : st( str.size() << 1 ),
        sz( 0 ),
        last( 0 )
   {
      st[ 0 ].len = 0;
      st[ 0 ].link = -1;
      ++sz;

      for( char sym : str )
		    Extend( sym );
   }

   std::string_view LCS( std::vector< char > const& t )
   {
      int32_t v = 0, l = 0, best = 0, bestpos = 0;
   	for( int32_t i = 0; i < t.size(); ++i )
      {
   		while( v && !st[v].next.count(t[i]) )
         {
   			v = st[v].link;
   			l = st[v].len;
   		}
   		if( st[v].next.count(t[i]) )
         {
   			v = st[v].next[t[i]];
   			++l;
   		}
   		if( l > best )
   			best = l,  bestpos = i;
   	}
      return std::string_view{ t.data()+bestpos-best+1, static_cast< size_t >( best ) };
   }

private:

   void Extend( char c )
   {
      int32_t cur = sz++;
   	st[cur].len = st[last].len + 1;
   	int32_t p;
   	for( p=last; p!=-1 && !st[p].next.count(c); p=st[p].link )
   		st[p].next[c] = cur;
   	if( p == -1 )
   		st[cur].link = 0;
   	else
      {
   		int32_t q = st[p].next[c];
   		if( st[p].len + 1 == st[q].len )
   			st[cur].link = q;
   		else
         {
   			int32_t clone = sz++;
   			st[clone].len = st[p].len + 1;
   			st[clone].next = st[q].next;
   			st[clone].link = st[q].link;
   			for (; p!=-1 && st[p].next[c]==q; p=st[p].link)
   				st[p].next[c] = clone;
   			st[q].link = st[cur].link = clone;
   		}
   	}
   	last = cur;
   }

   struct State
   {
      int32_t len;
      int32_t link;
      std::map< char, int32_t > next;
   };

   std::vector< State > st;
   int32_t sz;
   int32_t last;
};

int main()
{
   uint32_t N;
   std::scanf( "%" SCNu32, &N );

   std::vector< char > str1 = ReadString( N );
   std::vector< char > str2 = ReadString( N );

   std::string_view result = SA{ str1 }.LCS( str2 );
   std::printf( "%.*s\n", static_cast< int >( result.size() ), result.data() );

   return 0;
}
