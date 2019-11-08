#ifndef CIRCLEQUEUE_H_
#define CIRCLEQUEUE_H_

#include <iostream>

#include <tools/base/noncopyable.h>

#define DEFAULT_CAPACITY 10

template <typename T>
class CircleQueue : noncopyable {
public:
    CircleQueue() : 
        m_capacity(DEFAULT_CAPACITY),
        m_head(0),
        m_tail(0),
        m_data(new T[m_capacity+1]){}

    ~CircleQueue(){
        delete[] m_data;
    }

    int size() const {
        return (m_tail - m_head + m_capacity + 1) % (m_capacity + 1);
    }

    bool empty() const {
        return m_head == m_tail;
    }

    T& front() const {
        return m_data[m_head];
    }

    T& back() const {
        return m_data[(m_tail+m_capacity)%(m_capacity+1)];
    }

    void push(T elem){
        if((m_tail+1) % (m_capacity+1) == m_head){
            resize(m_capacity*2+1);
        }

        m_data[m_tail] = elem;
        ++ m_tail;
        m_tail %= m_capacity+1;
    }

    void pop(){
        ++ m_head;
        m_head %= m_capacity+1;

        if(m_capacity/2 >= DEFAULT_CAPACITY && size() == m_capacity/4){
            resize(m_capacity/2);
        }
    }

    // for unit test 
    void print(const char* name){
        int size = this->size();
        std::cout << name << "(CircleQueue): capacity = " << m_capacity << " size = " << size << '\n';
        if(size == 0){
            std::cout << "data = empty" << std::endl;
            return;
        }

        std::cout << "data = [";
        for(int i = 0; i < size; ++ i){
            std::cout << m_data[(m_head+i)%(m_capacity+1)] << ", ";
        }

        std::cout << "]" << std::endl;
    }

private:
    void resize(int newCapactiy){
        T* newData = new T[newCapactiy];
        int size = this->size();
        for(int i = 0; i < size; ++ i){
            newData[i] = m_data[(m_head+i)%(m_capacity+1)];
        }
        m_capacity = newCapactiy;
        m_head = 0;
        m_tail = size;
        m_data = newData;
    }

private:
    int m_capacity;
    int m_size;
    int m_head, m_tail; // tail指向队尾已有元素的下一个位置
    T* m_data;
};

#endif // CIRCLEQUEUE_H_