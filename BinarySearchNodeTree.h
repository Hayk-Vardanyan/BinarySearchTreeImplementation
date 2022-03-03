#ifndef _BINARY_NODE_TREE
#define _BINARY_NODE_TREE
#include "BinaryNode.h"

template< class ItemType>
class BinaryNodeTree
{
private:
    BinaryNode<ItemType>* rootPtr;

protected:
    BinaryNode<ItemType>* getRoot() const {return rootPtr;}
    BinaryNode<ItemType>* findNode(BinaryNode<ItemType>*,const ItemType&);
    void printInOrder(BinaryNode<ItemType>* rootPtr);
    void destroyTree(BinaryNode<ItemType>* subTreePtr);

    BinaryNode<ItemType>* removeValue(BinaryNode<ItemType>* subTreePtr, const ItemType& target, bool& success); 
    BinaryNode<ItemType>* removeNode(BinaryNode<ItemType>*);
    BinaryNode<ItemType>* findLeftMost(BinaryNode<ItemType>*,ItemType&);
	 
    BinaryNode<ItemType>* copyTree(const BinaryNode<ItemType>* treePtr);
    BinaryNode<ItemType>* insertInOrder(BinaryNode<ItemType>* rootPtr, BinaryNode<ItemType>* newNodePtr);

public:
    BinaryNodeTree();
    BinaryNodeTree( const ItemType& rootItem);
    BinaryNodeTree( const ItemType& rootItem, const BinaryNodeTree<ItemType>* leftTreePtr,const BinaryNodeTree<ItemType>* rightTreePtr);
    BinaryNodeTree( const BinaryNodeTree<ItemType>& tree);
   
    virtual ~BinaryNodeTree(){destroyTree(getRoot());}
   
    bool isEmpty() const {return rootPtr == nullptr;}
    bool add( const ItemType& newData);
    bool remove( const ItemType& data); 
    void clear(){destroyTree();}
    void print(){printInOrder(getRoot());}
    int find(const ItemType&);

    BinaryNodeTree& operator=(const BinaryNodeTree& rightHandSide);
}; 

#endif
