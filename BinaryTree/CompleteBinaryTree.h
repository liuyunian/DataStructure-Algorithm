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


	void pre_order(){
		std::cout << "pre order: ";
		pre_order(1);
		std::cout << std::endl;
	}

	void in_order(){
		std::cout << "in order: ";
		in_order(1);
		std::cout << std::endl;
	}

	void post_order(){
		std::cout << "post order: ";
		post_order(1);
		std::cout << std::endl;
	}

	void level_order(){
		std::cout << "level order: ";
		for(int i = 1; i < m_size+1; ++ i){
			std::cout << m_data[i] << ' ';
		}

		std::cout << std::endl;
	}

	// for unit test
	void print() const {
		// TODO：图形化方式打印完全二叉树
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