#include <iostream>
#include "BinaryNodeTree.h"
int main()
{
    BinaryNodeTree<int> bn;
    bn.add(100);
    bn.add(50);
    bn.add(150);
    bn.add(200);
    bn.remove(100);
    int result =  bn.find(100);
    if(result == -1) std::cout << "not found";
    else	
	std::cout << "element "  << result << "is found";
	
    std::cout << std::endl;
  
    BinaryNodeTree<int> bn2 = bn;
    bn2.print();
} 
