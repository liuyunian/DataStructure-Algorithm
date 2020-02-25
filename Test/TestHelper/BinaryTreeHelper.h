#ifndef BINARY_TREE_HELPER_H_
#define BINARY_TREE_HELPER_H_

#include <string>
#include <sstream>
#include <exception>

#include <stdlib.h> // srand rand
#include <time.h>   // time
#include <assert.h> // assert

#include "BinaryTree/CompleteBinaryTree.h"
#include "BinaryTree/BinaryTree.h"

CompleteBinaryTree<int> generate_complete_binary_tree_int(int size){
	int array[size];
	srand(time(NULL));
	for(int i = 0; i < size; ++ i){
		array[i] = rand() % size;
	}

	return CompleteBinaryTree<int>(size, array);
}

/**
 * @brief 由一串字符序列构造一个二叉树
*/
using Node = BinaryTree<int>::Node;

BinaryTree<int> generate_binary_tree_int(const std::string &str){
	if(str.empty()){
		throw std::runtime_error("str is empty");
	}

	std::stringstream ss(str);
	std::string item;
	std::getline(ss, item, ',');
	Node *root = new Node(std::stoi(item));
	int size = 1;
	std::queue<Node*> q;
	q.push(root);
	Node *node;
	while(!q.empty()){
		node = q.front();
		q.pop();
		std::getline(ss, item, ',');
		if(item != "$"){
			node->left = new Node(std::stoi(item));
			q.push(node->left);
			++ size;
		}
		std::getline(ss, item, ',');
		if(item != "$"){
			node->right = new Node(std::stoi(item));
			q.push(node->right);
			++ size;
		}
	}

	return BinaryTree<int>(root, size);
}

#endif // BINARY_TREE_HELPER_H_