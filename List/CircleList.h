#ifndef CIRCLELIST_H_
#define CIRCLELIST_H_

#include <iostream>

#include <tools/base/copyable.h>
#include <tools/base/noncopyable.h>

template <typename T>
class CircleList : copyable {
public:
    struct Node : noncopyable {
        T data;
        Node* next;

        Node(T elem) : data(elem), next(nullptr){}
    };

    CircleList() : m_tail(nullptr), m_size(0){}     // 默认构造函数
    CircleList(const CircleList& other) : 
        m_tail(nullptr),
        m_size(other.size())
    {
        if(m_size == 0){
            return;
        }

        m_tail = new Node(other.tail()->data);

        Node* preNode = m_tail;
        Node* selfNode;
        Node* otherNode = other.head();
        while(otherNode != other.tail()){
            selfNode = new Node(otherNode->data);
            preNode->next = selfNode;
            preNode = preNode->next;
            otherNode = otherNode->next;
        }
        preNode->next = m_tail;
    }

    ~CircleList(){
        clear();
    }

    Node* tail() const {
        return m_tail;
    }

    Node* head() const {
        return m_tail->next;
    }

    int size() const {
        return m_size;
    }

    bool empty() const {
        return m_size == 0;
    }

    void push_front(T elem){                        // 向链表头部添加元素
        Node* node = new Node(elem);
        if(m_tail == nullptr){
            m_tail = node;
            m_tail->next = m_tail;
        }
        else{
            node->next = m_tail->next;
            m_tail->next = node;
        }
        
        ++ m_size;
    }

    void pop_front(){                               // 移除链表头部的元素
        if(m_tail == nullptr){
            return;
        }

        if(m_size == 1){
            delete m_tail;
            m_tail = nullptr;
            -- m_size;
            return;
        }

        Node* node = m_tail->next;
        m_tail->next = node->next;
        delete node;

        -- m_size;
    }

    void push_back(T elem){                         // 向链表尾部添加元素
        Node* node = new Node(elem);
        if(m_tail == nullptr){
            m_tail = node;
            m_tail->next = m_tail;
        }
        else{
            node->next = m_tail->next;
            m_tail->next = node;
            m_tail = node;
        }

        ++ m_size;
    }

    void pop_back(){                                // 移除链表尾部的元素
        if(m_tail == nullptr){
            return;
        }

        if(m_size == 1){
            delete m_tail;
            m_tail = nullptr;
            -- m_size;
            return;
        }

        Node* preNode = m_tail->next;
        while(preNode->next != m_tail){
            preNode = preNode->next;
        }
        preNode->next = m_tail->next;
        delete m_tail;
        m_tail = preNode;

        -- m_size;
    }

    void operator=(const CircleList& other){
        clear();

        m_tail = nullptr;
        m_size = other.size();

        if(m_size == 0){
            return;
        }

        m_tail = new Node(other.tail()->data);
        Node* preNode = m_tail;
        Node* selfNode;
        Node* otherNode = other.head();
        while(otherNode != other.tail()){
            selfNode = new Node(otherNode->data);
            preNode->next = selfNode;
            preNode = selfNode;
            otherNode = otherNode->next;
        }
        preNode->next = m_tail;
    }

    // for pratice and it doesn't
    void insert(int index, T elem){}                // 向指定位置插入元素

    void remove(int index){}                        // 删除指定位置的元素

    void set(int index, T elem){}                   // 修改指定位置的元素

    T& get(int index) const {}                      // 获取指定位置的元素

    // for unit test
    void print(const char* name) const {
        std::cout << name << "(CircleList): size = " << m_size << '\n';
        std::cout << "data: ";
        if(m_size == 0){
            std::cout << "nullptr" << std::endl;
            return;
        }

        Node* node = head();
        for(int i = 0; i < m_size; ++ i){
            std::cout << node->data << " -> ";
            node = node->next;
        }
        std::cout << head()->data << std::endl;
    }

private:
    void clear(){
        Node* cur = m_tail;
        Node* next;
        for(int i = 0; i < m_size; ++ i){
            next = cur->next;
            delete cur;
            cur = next;
        }
    }

private:
    Node* m_tail;
    int m_size;
};

#endif // CIRCLELIST_H_