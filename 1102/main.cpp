#include <cstdint>
#include <iostream>
#include <string>
#include <map>
#include <list>
#include <memory>
#include <vector>

struct Node
{
   std::map< char, uint32_t > edges;
   bool isTerminal = false;
};

std::vector< Node > init_nodes()
{
    std::vector< Node > nodes( 16 );

    nodes[ 0 ].isTerminal = true;
    nodes[ 0 ].edges[ 'o' ] = 1;
    nodes[ 0 ].edges[ 'i' ] = 5;
    nodes[ 0 ].edges[ 'p' ] = 12;

    nodes[ 1 ].edges[ 'n' ] = 2;
    nodes[ 1 ].edges[ 'u' ] = 3;

    nodes[ 2 ].edges[ 'e' ] = 0;

    nodes[ 3 ].edges[ 't' ] = 4;

    nodes[ 4 ].isTerminal = true;
    nodes[ 4 ].edges[ 'p' ] = 7;
    nodes[ 4 ].edges[ 'o' ] = 1;
    nodes[ 4 ].edges[ 'i' ] = 5;

    nodes[ 5 ].edges[ 'n' ] = 6;

    nodes[ 6 ].isTerminal = true;
    nodes[ 6 ].edges[ 'p' ] = 7;
    nodes[ 6 ].edges[ 'o' ] = 1;
    nodes[ 6 ].edges[ 'i' ] = 5;

    nodes[ 7 ].edges[ 'u' ] = 8;

    nodes[ 8 ].edges[ 't' ] = 9;

    nodes[ 9 ].isTerminal = true;
    nodes[ 9 ].edges[ 'o' ] = 10;
    nodes[ 9 ].edges[ 'i' ] = 5;
    nodes[ 9 ].edges[ 'p' ] = 12;

    nodes[ 10 ].edges[ 'n' ] = 11;
    nodes[ 10 ].edges[ 'u' ] = 3;

    nodes[ 11 ].isTerminal = true;
    nodes[ 11 ].edges[ 'e' ] = 0;
    nodes[ 11 ].edges[ 'o' ] = 1;
    nodes[ 11 ].edges[ 'i' ] = 5;
    nodes[ 11 ].edges[ 'p' ] = 12;

    nodes[ 12 ].edges[ 'u' ] = 13;

    nodes[ 13 ].edges[ 't' ] = 14;

    nodes[ 14 ].edges[ 'o' ] = 15;

    nodes[ 15 ].edges[ 'n' ] = 0;

    return nodes;
}

bool check( std::string const& str )
{
    static std::vector< Node > const nodes = init_nodes();

    uint32_t pos = 0;
    for( uint32_t i = 0; i < str.size(); ++i )
    {
        auto const& node = nodes[ pos ];
        auto it = node.edges.find( str[ i ] );
        if( it == node.edges.end() )
            return false;
        pos = it->second;
    }
    return nodes[ pos ].isTerminal;
}

int main()
{
   uint32_t N;
   std::cin >> N >> std::ws;

   std::string str;
   for( uint32_t i = 0; i < N; ++i )
   {
      std::getline( std::cin, str );
      std::cout << ( check( str ) ? "YES" : "NO" ) << std::endl;
   }

   return 0;
}
