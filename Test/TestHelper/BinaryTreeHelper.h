#ifndef BINARY_TREE_HELPER_H_
#define BINARY_TREE_HELPER_H_

#include <stdlib.h> // srand rand
#include <time.h>   // time
#include <assert.h> // assert

#include "BinaryTree/CompleteBinaryTree.h"

CompleteBinaryTree<int> generate_int_completeBinaryTree(int size){
	int array[size];
	srand(time(NULL));
	for(int i = 0; i < size; ++ i){
		array[i] = rand() % size;
	}

	CompleteBinaryTree<int> cbt(size, array);
	return cbt;
}

#endif // BINARY_TREE_HELPER_H_