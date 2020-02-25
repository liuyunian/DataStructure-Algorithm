#ifndef COMPLETE_BINARY_TREE_H_
#define COMPLETE_BINARY_TREE_H_

#include <iostream>

#include <tools/base/copyable.h>

template <typename T>
class CompleteBinaryTree : copyable {
public:
	CompleteBinaryTree(int size, T data[]) :
		m_size(size),
		m_data(new T[m_size+1])
	{
		for(int i = 1; i < m_size+1; ++ i){
			m_data[i] = data[i-1];
		}
	}

	CompleteBinaryTree(const CompleteBinaryTree &other) : 
		m_size(other.m_size),
		m_data(new T[m_size+1])
	{
		for(int i = 1; i < m_size+1; ++ i){
			m_data[i] = other.m_data[i];
		}
	}
	
	~CompleteBinaryTree(){
		delete[] m_data;
	}

	CompleteBinaryTree& operator=(const CompleteBinaryTree &other){
		this->~CompleteBinaryTree();
		m_size = other.m_size;
		m_data = new T[m_size+1];

		for(int i = 1; i < m_size+1; ++ i){
			m_data[i] = other.m_data[i];
		}

		return *this;
	}

	int size() const {
		return m_size;
	}

	bool empty() const {
		return m_size == 0;
	}

	/**
	 * @brief 前序遍历（迭代）
	*/
	void pre_order(){
		// TODO
	}

	/**
	 * @brief 前序遍历（递归）
	*/
	void pre_order_recursive(){
		std::cout << "pre order: ";
		pre_order(1);
		std::cout << std::endl;
	}

	/**
	 * @brief 中序遍历（迭代）
	*/
	void in_order(){
		// TODO
	}

	/**
	 * @brief 中序遍历（递归）
	*/
	void in_order_recursive(){
		std::cout << "in order: ";
		in_order(1);
		std::cout << std::endl;
	}

	/**
	 * @brief 后序遍历（迭代）
	*/
	void post_order(){
		// TODO
	}

	/**
	 * @brief 后序遍历（递归）
	*/
	void post_order_recursive(){
		std::cout << "post order: ";
		post_order(1);
		std::cout << std::endl;
	}

	/**
	 * @brief 层序遍历
	*/
	void level_order(){
		std::cout << "level order: ";
		for(int i = 1; i < m_size+1; ++ i){
			std::cout << m_data[i] << ' ';
		}

		std::cout << std::endl;
	}

private:
	void pre_order(int index){
		if(index > m_size){
			return;
		}

		std::cout << m_data[index] << ' ';
		pre_order(index*2);
		pre_order(index*2+1);
	}

	void in_order(int index){
		if(index > m_size){
			return;
		}

		in_order(index*2);
		std::cout << m_data[index] << ' ';
		in_order(index*2+1);		
	}

	void post_order(int index){
		if(index > m_size){
			return;
		}

		post_order(index*2);
		post_order(index*2+1);
		std::cout << m_data[index] << ' ';
	}

private:
	int m_size;
	T *m_data;
};

#endif // COMPLETE_BINARY_TREE_H_