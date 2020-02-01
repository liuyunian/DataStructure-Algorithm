#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#include <iostream>
#include <queue>

#include <tools/base/copyable.h>

template<typename T>
class BinaryTree : copyable {
private:
	struct Node{
		T data;
		Node *left;
		Node *right;

		Node(T elem) : data(elem), left(nullptr), right(nullptr) {}
	};

public:
	BinaryTree() : 
		m_root(nullptr),
		m_size(0)
	{}

	BinaryTree(const BinaryTree &other) {
		// TODO
	}

	~BinaryTree(){
		std::queue<Node*> q;
		q.push(m_root);
		while(!q.empty()){
			Node *node = q.front();
			if(node->left != nullptr){
				q.push(node->left);
			}

			if(node->right != nullptr){
				q.push(node->right);
			}

			delete node;
			q.pop();
		}
	}

	int size() const {
		return size;
	}

	bool empty() const {
		return size == 0;
	}

	BinaryTree& operator=(const BinaryTree &other){
		// TODO
	}

	void pre_order(){
		std::cout << "pre order: ";
		pre_order(m_root);
		std::cout << std::endl;
	}

	void in_order(){
		std::cout << "in order: ";
		in_order(m_root);
		std::cout << std::endl;
	}    

	void post_order(){
		std::cout << "post order: ";
		post_order(m_root);
		std::cout << std::endl;
	}

	void level_order(){
		std::cout << "level order: ";

		std::queue<Node*> q;
		q.push(m_root);
		while(!q.empty()){
			Node *node = q.front();
			if(node->left != nullptr){
				q.push(node->left);
			}

			if(node->right != nullptr){
				q.push(node->right);
			}

			std::cout << node->data << ' ';
			q.pop();
		}

		std::cout << std::endl;
	}

	// for unit test
	void print() const {
		// TODO：图形化方式打印二叉树
	}

private:
	void pre_order(Node *node){
		if(node == nullptr){
			return;
		}

		std::cout << node->data << ' ';
		pre_order(node->left);
		pre_order(node->right);
	}

	void in_order(Node *node){
		if(node == nullptr){
			return;
		}

		in_order(node->left);
		std::cout << node->data << ' ';
		in_order(node->right);
	}

	void post_order(Node *node){
		if(node == nullptr){
			return;
		}

		post_order(node->left);
		post_order(node->right);
		std::cout << node->data << ' ';
	}

private:
	Node *m_root;
	int m_size;
};

#endif // BINARY_TREE_H_