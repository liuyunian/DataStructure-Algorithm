#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_

#include <iostream>
#include <queue>

#include "tools/base/copyable.h"

namespace set {
template<typename T>
class BinarySearchTree : copyable {
private:
	struct Node {
		T data;
		Node *left;
		Node *right;

		Node(T val) : data(val), left(nullptr), right(nullptr){}
	};

public:
	BinarySearchTree() : m_root(nullptr), m_size(0){}

	BinarySearchTree(const BinarySearchTree &other){ /* TODO */ }

	~BinarySearchTree(){
		if(m_root == nullptr){
			return;
		}

		std::queue<Node*> q;
		q.push(m_root);
		Node *cur;
		while(!q.empty()){
			cur = q.front();
			q.pop();
			if(cur->left){
				q.push(cur->left);
			}

			if(cur->right){
				q.push(cur->right);
			}

			delete cur;
		}
	}

	int size() const {
		return m_size;
	}

	bool empty() const {
		return m_size == 0;
	}

	BinarySearchTree& operator=(const BinarySearchTree &other){ 
		// TODO
	}

	/**
	 * @brief 插入结点（迭代）
	*/
	void insert(T data){
		if(m_root == nullptr){
			m_root = new Node(data);
			return;
		}

		Node *cur = m_root;
		Node *parent;
		while(cur != nullptr){
			parent = cur;
			if(cur->data == data){
				return;
			}
			else if(cur->data > data){
				cur = cur->left;
			}
			else{
				cur = cur->right;
			}
		}

		if(parent->data > data){
			parent->left = new Node(data);
		}
		else if(parent->data < data){
			parent->right = new Node(data);
		}
	}

	/**
	 * @brief 插入结点（递归）
	*/
	void insert_recursive(T data){
		m_root = insert(m_root, data);
	}

	/**
	 * @brief 查找（迭代）
	 * @return 成功找到返回true，否则返回false
	*/
	bool find(T data) const {
		Node *cur = m_root;
		while(cur != nullptr){
			if(data == cur->data){
				return true;
			}
			else if(data < cur->data){
				cur = cur->left;
			}
			else{
				cur = cur->right;
			}
		}

		return false;
	}

	/**
	 * @brief 查找（递归）
	 * @return 成功找到返回true，否则返回false
	*/
	bool find_recursive(T data) const {
		return find(m_root, data);
	}

	/**
	 * @brief 删除结点（迭代）
	*/
	void erase(T data){
		// TODO
	}

	/**
	 * @brief 删除结点（递归）
	*/
	void erase_recursive(T data){
		if(m_size == 0){
			return;
		}

		m_root = erase(m_root, data);
	}

	// for unit test
	void print() const {
		std::cout << "Binary Search Tree: size = " << m_size << '\n';
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
				if(cur != nullptr){
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
	Node* insert(Node *node, T data){
		if(node == nullptr){
			++ m_size;
			return new Node(data);
		}

		if(data < node->data){
			node->left = insert(node->left, data);
		}
		else if(data > node->data){
			node->right = insert(node->right, data);
		}

		return node;
	}

	bool find(Node *node, T data) const {
		if(node == nullptr){
			return false;
		}

		if(data == node->data){
			return true;
		}
		else if(data < node->data){
			return find(node->left, data);
		}
		else{
			return find(node->right, data);
		}
	}

	Node* erase(Node *node, T data){
		if(node == nullptr){
			return nullptr;
		}

		if(node->data > data){
			node->left = erase(node->left, data);
			return node;
		}
		else if(node->data < data){
			node->right = erase(node->right, data);
			return node;
		}
		else{
			if(node->left == nullptr){
				Node *right = node->right;
				delete node;
				-- m_size;
				return right;
			}

			if(node->right == nullptr){
				Node *left = node->left;
				delete node;
				-- m_size;
				return left;
			}

			if(node->left != nullptr && node->right != nullptr){
				Node *successor = new Node(get_min(node->right));
				successor->right = earse_min(node->right);
				successor->left = node->left;

				delete node;
				-- m_size;
				return successor;
			}
		}
	}

	T get_min(Node *node) const {
    if(node->left == nullptr){
			return node->data;
    }

    return get_min(node->left);
	}

	Node *earse_min(Node *node){
    if(node->left == nullptr){ 
			Node *right = node->right;
			delete node;
			-- m_size;
			return right;
    }

    node->left = earse_min(node->left);
    return node;
	}

private:
	Node *m_root;
	int m_size;
};

}; // namespace Set

namespace map {
// template<typename Key, typename Value>
// class BinarySearchTree : copyable {
// private:
// 	struct Node {
// 		Key key;
// 		Value value;
// 		Node *left;
// 		Node *right;

// 		Node(Key k, Value val) : key(k), value(val), left(nullptr), right(nullptr){}
// 	};

// public:
// 	BinarySearchTree() : m_root(nullptr), m_size(0){}

// 	BinarySearchTree(const BinarySearchTree &other){ /* TODO */ }

// 	~BinarySearchTree() = default;

// 	int size() const {
// 		return m_size;
// 	}

// 	bool empty() const {
// 		return m_size == 0;
// 	}

// 	/**
// 	 * @brief 插入结点（迭代）
// 	*/
// 	void insert(Key k, Value val){

// 	}

// 	/**
// 	 * @brief 插入结点（递归）
// 	*/
// 	void insert_recursive(Key k, Value val){
// 		insert(m_root, k, val);
// 	}

// 	// for unit test
// 	void print() const {

// 	}

// private:
// 	Node* insert(Node *node, Key key, Value val){
		
// 	}

// private:
// 	Node *m_root;
// 	int m_size;
// };

} // namespace map

#endif // BINARY_SEARCH_TREE_H_