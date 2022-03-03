#include "BinaryNode.h"
#include "BinaryNodeTree.h"
#include <iostream>

template <typename ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree() : rootPtr(nullptr) {}

template <typename ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& item)
{
    rootPtr = new BinaryNode<ItemType>(item, nullptr, nullptr);
}

template <class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree( const ItemType& rootItem,const BinaryNodeTree<ItemType>* leftTreePtr,
const BinaryNodeTree<ItemType>* rightTreePtr)
{
    rootPtr = new BinaryNode<ItemType>(rootItem,
    copyTree(leftTreePtr->rootPtr),
    copyTree(rightTreePtr->rootPtr));
}

template <typename ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::copyTree(const BinaryNode<ItemType>* treePtr)
{
  
    BinaryNode<ItemType>* newPtr = nullptr;
   
    if(treePtr != nullptr)
    { 
        newPtr = new BinaryNode<ItemType>(treePtr->getItem());
        newPtr->setLeftChildPtr(copyTree(treePtr->getLeftChildPtr()));
        newPtr->setRightChildPtr(copyTree(treePtr->getRightChildPtr()));
    } 
   
    return newPtr; 
} 

template <typename ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const BinaryNodeTree<ItemType>& treePtr)
{ 
	rootPtr = copyTree(treePtr.getRoot());
} 

template <typename ItemType>
void BinaryNodeTree<ItemType>::destroyTree(BinaryNode<ItemType>* treePtr)
{
    if(treePtr != nullptr)
    {
        destroyTree(treePtr->getLeftChildPtr());
        destroyTree(treePtr->getRightChildPtr());
        delete treePtr;
    }
}


template< class ItemType>
bool BinaryNodeTree<ItemType>::add(const ItemType& newData)
{
    BinaryNode<ItemType>* newPtr = new BinaryNode<ItemType>(newData, nullptr, nullptr);
    rootPtr = insertInOrder(rootPtr, newPtr);

    return true;
} 

template< class ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::insertInOrder(BinaryNode<ItemType>* rootPtr, BinaryNode<ItemType>* newPtr)
{
   
    if(rootPtr == nullptr) return newPtr;
   
    else if(rootPtr->getItem() > newPtr->getItem())
    {
        BinaryNode<ItemType>* tmp = insertInOrder(rootPtr->getLeftChildPtr(), newPtr);
        rootPtr->setLeftChildPtr(tmp);
    }
    else if(rootPtr->getItem() < newPtr->getItem())
    {
        BinaryNode<ItemType>* tmp = insertInOrder(rootPtr->getRightChildPtr(), newPtr);
        rootPtr->setRightChildPtr(tmp);
    }
   
    return rootPtr;
}

template <typename ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::findNode(BinaryNode<ItemType>* rootPtr,const ItemType& target)
{
    if(rootPtr == nullptr) return nullptr;
   
    else if(rootPtr->getItem() == target)
    {
        return rootPtr;
    }
   
    else if(rootPtr->getItem() > target)
    {
        return findNode(rootPtr->getLeftChildPtr(), target);
    }
    else if(rootPtr->getItem() < target)
    {
        return findNode(rootPtr->getRightChildPtr(), target);
    }
}

template <typename ItemType>
int BinaryNodeTree<ItemType>::find(const ItemType& item)
{
    BinaryNode<ItemType>* result = findNode(getRoot(), item);
    if(result != nullptr) return result->getItem();
   
   
    return -1;
}


template< class ItemType>
void BinaryNodeTree<ItemType>::printInOrder(BinaryNode<ItemType>* rootPtr)
{
    if(rootPtr != nullptr)
    {
        printInOrder(rootPtr->getLeftChildPtr());
        std::cout << rootPtr->getItem() << " ";
        printInOrder(rootPtr->getRightChildPtr());
    }
}


template <typename ItemType>
bool BinaryNodeTree<ItemType>::remove(const ItemType& item)
{
    bool success = false;
    removeValue(rootPtr, item, success);
    return success;
}

template <typename ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::removeValue(BinaryNode<ItemType>* rootPtr, const ItemType& target, bool& success)
{
    if (rootPtr == nullptr)
    {
        success = false;
        return nullptr;
    }
    else if (rootPtr->getItem() == target)
    {
        rootPtr = removeNode(rootPtr); 
        success = true;
        return rootPtr;
    }
    else if (rootPtr->getItem() > target)
    {
        BinaryNode<ItemType>* tempPtr = removeValue(rootPtr->getLeftChildPtr(), target, success);
        rootPtr->setLeftChildPtr(tempPtr);
        return rootPtr;
    }
    else
    {
        BinaryNode<ItemType>* tempPtr = removeValue(rootPtr->getRightChildPtr(), target, success);
        rootPtr->setRightChildPtr(tempPtr);
        return rootPtr;
    }
    
}

template <typename ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::removeNode(BinaryNode<ItemType>* nodePtr)
{
    if((nodePtr->getRightChildPtr() == nullptr) && (nodePtr->getLeftChildPtr() == nullptr))
    {
        delete nodePtr;
        nodePtr = nullptr;
        return nodePtr;
    }
    
    else if((nodePtr->getLeftChildPtr() == nullptr && nodePtr->getRightChildPtr() != nullptr) || 
    (nodePtr->getLeftChildPtr() != nullptr && nodePtr->getRightChildPtr() == nullptr))
    {
        BinaryNode<ItemType>* connectNode{};
        if(nodePtr->getLeftChildPtr() != nullptr)
            connectNode = nodePtr->getLeftChildPtr();
        else
            connectNode = nodePtr->getRightChildPtr();
        
        delete nodePtr;
        nodePtr = nullptr;
        return connectNode;
    }
    else 
        {
            ItemType newItem{}; 
            BinaryNode<ItemType>* tmp = findLeftMost(nodePtr->getRightChildPtr(), newItem);
            nodePtr->setRightChildPtr(tmp);
	    nodePtr->setItem(newItem);
            return nodePtr;
        }
}

template <typename ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::findLeftMost(BinaryNode<ItemType>* nodePtr,ItemType& newItem)
{
    if(nodePtr->getLeftChildPtr() == nullptr)
    {
        newItem = nodePtr->getItem();
        return removeNode(nodePtr);
    }
    else 
        return findLeftMost(nodePtr->getLeftChildPtr(), newItem);
}


