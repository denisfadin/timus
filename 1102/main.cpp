#include <cstdint>
#include <iostream>
#include <string>
#include <map>
#include <list>
#include <memory>
#include <vector>

struct Node
{
   std::map< char, Node* > edges;
   bool leaf = false;
};

int main()
{
   std::vector< std::string > const dict = {
      "out",
      "output",
      "outputon", // +
      "outputone", // +
      "in",
      "input",
      "inputon", // +
      "inputone", // +
      "puton",
      "one"
   };

   std::list< std::unique_ptr< Node > > nodes;
   nodes.push_back( std::make_unique< Node >() );

   for( auto const& str : dict )
   {
      Node* curr = nodes.front().get();
      for( auto const sym : str )
      {
         auto it = curr->edges.find( sym );
         if( it != curr->edges.end() )
            curr = it->second;
         else
         {
            nodes.push_back( std::make_unique< Node >() );
            curr->edges[ sym ] = nodes.back().get();
            curr = nodes.back().get();
         }
      }
      curr->leaf = true;
   }

   for( auto const& node : nodes )
   {
      if( !node->leaf )
         continue;

      Node const* root = nodes.front().get();
      for( auto const& edge : root->edges )
      {
         auto it = node->edges.find( edge.first );
         if( it != node->edges.end() )
            continue;
         node->edges[ edge.first ] = edge.second;
      }
   }

   /*auto get_node = [ & ]( std::string const& str )
   {
      Node* curr = nodes.front().get();
      for( auto sym : str )
         curr = curr->edges[ sym ];
      return curr;
   };

   get_node( "input" )->edges[ 'o' ] = get_node( "puto" );
   get_node( "output" )->edges[ 'o' ] = get_node( "puto" );*/


   uint32_t N;
   std::cin >> N >> std::ws;

   std::string str;
   str.reserve( 10000000 );

   for( uint32_t i = 0; i < N; ++i )
   {
      std::getline( std::cin, str );
      Node* curr = nodes.front().get();
      for( auto sym : str )
      {
          std::cout << sym << std::endl;
         auto it = curr->edges.find( sym );
         if( it == curr->edges.end() )
         {
            curr = nullptr;
            break;
         }
         else
            curr = it->second;
      }

      if( curr && curr->leaf )
         std::cout << "YES" << std::endl;
      else
         std::cout << "NO" << std::endl;
   }

   return 0;
}
