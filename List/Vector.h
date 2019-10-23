#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>

#include <assert.h>

#include "tools/base/copyable.h"

#define DEFAULT_CAPACITY 10

template <typename T>
class Vector : copyable {
public:
    explicit Vector(int capacity) : 
        m_capacity(capacity),
        m_size(0),
        m_data(new T[m_capacity]){}

    Vector() : Vector(DEFAULT_CAPACITY){}

    Vector(const Vector& other) :                   // 拷贝构造函数
        m_capacity(other.capacity()),
        m_size(other.size()),
        m_data(new T[m_capacity]){
            for(int i = 0; i < m_size; ++ i){
                m_data[i] = other.at(i);            // m_data[i] = other[i]报错
            }
        }

    ~Vector(){
        delete[] m_data;
    }

    T& operator[](int index){                       // 重载[]
        assert(index >= 0 && index < m_size);
        return m_data[index];
    }

    void operator=(const Vector& other){            // 重载=
        m_capacity = other.capacity();
        m_size = other.size();
        delete[] m_data;
        m_data = new T[m_capacity];
        for(int i = 0; i < m_size; ++ i){
            m_data[i] = other.at(i);
        }
    }

    int size() const {
        return m_size;
    }

    int capacity() const {
        return m_capacity;
    }

    bool empty() const {
        return m_size == 0;
    }

    void insert(int index, T elem){
        if(m_size == m_capacity){
            resize(m_capacity * 2);                 // 扩容成原来的两倍
        }

        assert(index >= 0 && index <= m_size);
        for(int i = m_size; i > index; -- i){
            m_data[i] = m_data[i-1];
        }

        m_data[index] = elem;
        ++ m_size;
    }

    void push_front(T elem){
        insert(0, elem);
    }

    void push_back(T elem){
        insert(m_size, elem);
    }

    T& at(int index) const {
        assert(index >= 0 && index < m_size);
        return m_data[index];
    }

    T& front() const {
        at(0);
    }

    T& back() const {
        at(m_size - 1);
    } 

    void remove(int index){
        assert(index >= 0 && index < m_size);
        for(int i = index + 1; i < m_size; ++ i){
            m_data[i - 1] = m_data[i]; 
        }

        -- m_size;

        if(m_capacity / 2 >= DEFAULT_CAPACITY && m_size == m_capacity / 4){ // 当容量大于20，但是存储的元素个数不到容量的1/4时进行缩容
            resize(m_capacity / 2);
        }
    }

    void pop_front(){
        remove(0);
    }

    void pop_back(){
        remove(m_size - 1);
    }

    void resize(int newCapacity){
        T* newData = new T[newCapacity];
        for(int i = 0; i < m_size; ++ i){
            newData[i] = m_data[i];
        }

        m_data = newData;
        m_capacity = newCapacity;
    }

    int find(const T& elem) const {
        for(int i = 0; i < m_size; ++ i){
            if(m_data[i] == elem){
                return i;
            }
        }

        return -1;
    }

    // for test
    void print() const {
        std::cout << "capacity = " << m_capacity << ", size = " << m_size << std::endl;
        std::cout << "data = [";
        for(int i = 0; i < m_size - 1; ++ i){
            std::cout << m_data[i] << ", ";
        }
        std::cout << m_data[m_size - 1] << "]" << std::endl;
    }

private:
    int m_capacity;
    int m_size;
    T* m_data;
}; 

#endif // VECTOR_H_