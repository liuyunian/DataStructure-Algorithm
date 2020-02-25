#ifndef STACK_H_
#define STACK_H_

#include <iostream>

#include <tools/base/noncopyable.h>

#include "List/Deque.h"

template <typename T, typename Container = Deque<T>>
class Stack : noncopyable {
public:
	Stack() = default;
	~Stack() = default;

	int size() const {
		return m_container.size();
	}

	bool empty() const {
		return m_container.empty();
	}

	void push(T elem){
		m_container.push_back(elem);
	}

	void pop(){
		m_container.pop_back();
	}

	T& top() const {
		return m_container.back();
	}

	// for unit test
	void print(const char* name) const {
		m_container.print(name);
	}

private:
	Container m_container;
};

#endif // STACK_H_