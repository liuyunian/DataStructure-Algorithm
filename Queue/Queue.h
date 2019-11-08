#ifndef QUEUE_H_
#define QUEUE_H_

#include <tools/base/noncopyable.h>

#include "List/Deque.h"

template <typename T, typename Container = Deque<T>>
class Queue : noncopyable {
public:
    Queue() = default;
    ~Queue() = default;

    int size() const {
        return m_container.size();
    }

    bool empty() const {
        return m_container.empty();
    }

    T& front() const {
        return m_container.front();
    }

    T& back() const {
        return m_container.back();
    }

    void push(T elem){
        m_container.push_back(elem);
    }

    void pop(){
        m_container.pop_front();
    }

    // for unit test
    void print(const char* name){
        m_container.print(name);
    }

private:
    Container m_container;
};

#endif // QUEUE_H_