#ifndef _BINARY_NODE
#define _BINARY_NODE
template< class ItemType>
class BinaryNode
{
private:
    ItemType item;
    BinaryNode<ItemType>* leftChildPtr; 
    BinaryNode<ItemType>* rightChildPtr; 
public:
    BinaryNode();
    BinaryNode( const ItemType& anItem) {item = anItem; leftChildPtr = nullptr; rightChildPtr = nullptr;}
    BinaryNode( const ItemType& anItem, BinaryNode<ItemType>* leftPtr, BinaryNode<ItemType>* rightPtr) {item = anItem; leftChildPtr = leftPtr; 
    rightChildPtr = rightPtr;}
    
    void setItem( const ItemType& anItem) {item = anItem;}
    ItemType getItem() const {return item;}
   
    BinaryNode<ItemType>* getLeftChildPtr() const {return leftChildPtr;}
    BinaryNode<ItemType>* getRightChildPtr() const {return rightChildPtr;}
    void setLeftChildPtr(BinaryNode<ItemType>* leftPtr) {leftChildPtr = leftPtr;}
    void setRightChildPtr(BinaryNode<ItemType>* rightPtr) {rightChildPtr = rightPtr;}
}; 
#endif
