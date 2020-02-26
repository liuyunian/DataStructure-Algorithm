#include <iostream>
#include "BinaryTree/BinarySearchTree.h"

int main(){
	set::BinarySearchTree<int> bstSet;
	for(int i = 9; i >= 0; -- i){
		bstSet.insert(i);																															// test insert
	}

	for(int i = 10; i < 20; ++ i){
		bstSet.insert_recursive(i);																										// test insert_recursive
	}

	bstSet.print();

	std::cout << "find 5: " << std::boolalpha << bstSet.find(5) << std::endl;				// test find
	std::cout << "find 25: " << bstSet.find_recursive(25) << std::endl;							// test find_recursive

	bstSet.erase_recursive(15);																											// test erase_recursive
	bstSet.print();

	return 0;
}