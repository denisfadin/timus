#include <iostream>
#include <cinttypes>
#include <memory>
#include <vector>
#include <functional>

class BinaryTree
{
public:

   void Insert( uint32_t value );
   void WalkRight( std::function< void ( uint32_t value ) > const& cb ) const;

private:

   struct Node
   {
      uint32_t mValue;
      std::unique_ptr< Node > mLeft;
      std::unique_ptr< Node > mRight;
   };

   std::unique_ptr< Node > mRoot;

   void DoWalkRight( Node const& node, std::function< void ( uint32_t value ) > const& cb ) const;
};

void BinaryTree::Insert( uint32_t value )
{
   std::unique_ptr< Node > new_node{ new Node{ .mValue = value } };

   if( !mRoot )
   {
      mRoot = std::move( new_node );
      return;
   }

   Node* parent = mRoot.get();
   while( true )
   {
      if( value > parent->mValue )
      {
         if( parent->mRight )
         {
            parent = parent->mRight.get();
            continue;
         }
         else
         {
            parent->mRight = std::move( new_node );
            return;
         }
      }
      else
      {
         if( parent->mLeft )
         {
            parent = parent->mLeft.get();
            continue;
         }
         else
         {
            parent->mLeft = std::move( new_node );
            return;
         }
      }
   }
}

void BinaryTree::WalkRight( std::function< void ( uint32_t value ) > const& cb ) const
{
   if( mRoot )
      DoWalkRight( *mRoot, cb );
}

void BinaryTree::DoWalkRight( Node const& node, std::function< void ( uint32_t value ) > const& cb ) const
{
   if( node.mRight )
      DoWalkRight( *node.mRight, cb );
   if( node.mLeft )
      DoWalkRight( *node.mLeft, cb );
   cb( node.mValue );
}

int main()
{
   uint32_t N;
   std::cin >> N;

   std::vector< uint32_t > buf;
   for( uint32_t i = 0; i < N; ++i )
   {
      uint32_t value;
      std::cin >> value;
      buf.push_back( value );
   }

   BinaryTree tree;
   for( auto it = buf.rbegin(); it != buf.rend(); ++it )
      tree.Insert( *it );

   tree.WalkRight( []( uint32_t value )
   {
      std::cout << value << std::endl;
   });

   return 0;
}
