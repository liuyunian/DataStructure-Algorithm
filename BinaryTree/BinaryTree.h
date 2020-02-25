#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#include <iostream>
#include <queue>
#include <stack>

#include <tools/base/copyable.h>

template<typename T>
class BinaryTree : copyable {
public:
	struct Node{
		T data;
		Node *left;
		Node *right;

		Node(T elem) : data(elem), left(nullptr), right(nullptr) {}
	};

	BinaryTree(Node *root, int size) : 
		m_root(root),
		m_size(size)
	{}

	BinaryTree(const BinaryTree &other) : 
		m_root(nullptr),
		m_size(other.m_size)
	{
		std::queue<Node*> otherQ, q;
		m_root = new Node(0);
		q.push(m_root);
		otherQ.push(other.m_root);
		Node *otherCur, *cur;
		while(!otherQ.empty()){
			otherCur = otherQ.front();
			cur = q.front();
			otherQ.pop();
			q.pop();
			cur->data = otherCur->data;

			if(otherCur->left){
				otherQ.push(otherCur->left);
				cur->left = new Node(0);
				q.push(cur->left);
			}

			if(otherCur->right){
				otherQ.push(otherCur->right);
				cur->right = new Node(0);
				q.push(cur->right);
			}
		}
	}

	~BinaryTree(){
		std::queue<Node*> q;
		q.push(m_root);
		while(!q.empty()){
			Node *cur = q.front();
			if(cur->left != nullptr){
				q.push(cur->left);
			}

			if(cur->right != nullptr){
				q.push(cur->right);
			}

			delete cur;
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

	/**
	 * @brief 前序遍历（迭代）
	*/
	void pre_order(){
		std::cout << "pre order: ";
		std::stack<Node*> s;
		Node *cur = m_root;
		while(cur != nullptr || !s.empty()){
			while(cur != nullptr){
				std::cout << cur->data << ' ';
				s.push(cur);
				cur = cur->left;
			}

			if(!s.empty()){
				cur = s.top();
				s.pop();
				cur = cur->right;
			}
		}
		std::cout << std::endl;
	}

	/**
	 * @brief 前序遍历（递归）
	*/
	void pre_order_recursive(){
		std::cout << "pre order: ";
		pre_order(m_root);
		std::cout << std::endl;
	}

	/**
	 * @brief 中序遍历（迭代）
	*/
	void in_order(){
		std::cout << "in order: ";
		std::stack<Node*> s;
		Node *cur = m_root;
		while(cur != nullptr || !s.empty()){
			while(cur != nullptr){
				s.push(cur);
				cur = cur->left;
			}

			if(!s.empty()){
				cur = s.top();
				std::cout << cur->data << ' ';
				s.pop();
				cur = cur->right;
			}
		}
		std::cout << std::endl;
	}

	/**
	 * @brief 中序遍历（递归）
	*/
	void in_order_recursive(){
		std::cout << "in order: ";
		in_order(m_root);
		std::cout << std::endl;
	}

	/**
	 * @brief 后序遍历（迭代）
	*/
	void post_order(){
		std::cout << "post order: ";
		std::stack<Node*> s;
		Node *cur = m_root, *pre = nullptr;
		while(cur != nullptr || !s.empty()){
			while(cur != nullptr){
				s.push(cur);
				cur = cur->left;
			}

			if(!s.empty()){
				cur = s.top();
				if(cur->right == nullptr || cur->right == pre){
					std::cout << cur->data << ' ';
					pre = cur;
					cur = nullptr;
					s.pop();
				}
				else{
					cur = cur->right;
				}
			}
		}
		std::cout << std::endl;
	}

	/**
	 * @brief 后序遍历（递归）
	*/
	void post_order_recursive(){
		std::cout << "post order: ";
		post_order(m_root);
		std::cout << std::endl;
	}

	/**
	 * @brief 层序遍历
	*/
	void level_order(){
		std::cout << "level order: ";

		std::queue<Node*> q;
		q.push(m_root);
		while(!q.empty()){
			Node *cur = q.front();
			if(cur->left != nullptr){
				q.push(cur->left);
			}

			if(cur->right != nullptr){
				q.push(cur->right);
			}

			std::cout << cur->data << ' ';
			q.pop();
		}

		std::cout << std::endl;
	}

	// for unit test
	void print() const {
		std::cout << "BinaryTree: size = " << m_size << '\n';
		if(m_root == nullptr){
			std::cout << "NULL" << std::endl;
			return;
		}

		std::queue<Node*> q;
		q.push(m_root);
		int size;
		Node *cur;
		while(!q.empty()){
			size = q.size();
			while(size > 0){
				cur = q.front();
				q.pop();
				if(cur){
					std::cout << cur->data << ' ';
					q.push(cur->left);
					q.push(cur->right);
				}
				else{
					std::cout << "NULL ";
				}

				-- size;
			}

			std::cout << std::endl;
		}
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