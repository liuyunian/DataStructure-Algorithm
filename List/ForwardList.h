#ifndef FORWARDLIST_H_
#define FORWARDLIST_H_

#include <iostream>

#include <tools/base/copyable.h>
#include <tools/base/noncopyable.h>

template <typename T>
class ForwardList : copyable {
private:
    struct Node : noncopyable {
        T data;
        Node* next;

        Node(T elem) : data(elem), next(nullptr) {}
    };

public:
    ForwardList() : 
        m_head(nullptr), 
        m_size(0){}                                 // 默认构造函数

    ForwardList(const ForwardList& other) :         // 拷贝构造函数
        m_head(nullptr), 
        m_size(other.size())
    {         
        if(other.empty()){
            return;
        }

        m_head = new Node(other.head()->data);
        if(other.size() == 1){
            return;
        }

        Node* preNode = m_head;
        Node* selfNode;
        Node* otherNode = other.head()->next;
        while(otherNode != nullptr){
            selfNode = new Node(otherNode->data);
            preNode->next = selfNode;
            preNode = preNode->next;
            otherNode = otherNode->next;
        }
    }

    ~ForwardList(){
        Node* curNode = m_head;
        Node* nextNode;
        while(curNode != nullptr){
            nextNode = curNode->next;
            delete curNode;
            curNode = nextNode;
        }
    }

    int size() const {
        return m_size;
    }

    bool empty() const {
        return m_size == 0;
    }

    Node* head() const {
        return m_head;
    }

    void push_front(T elem){                        // 向链表头部添加元素
        Node* node = new Node(elem);
        node->next = m_head;
        m_head = node;

        ++ m_size; 
    }

    void pop_front(){                               // 移除链表头部的元素
        if(m_head == nullptr){
            return;
        }

        Node* node = m_head->next;
        delete m_head;
        m_head = node;

        -- m_size;
    }

    void push_back(T elem){                         // 向链表尾部添加元素
        Node* node = new Node(elem);
        if(m_head == nullptr){
            m_head = node;
        }
        else{
            Node* tailNode = m_head;
            while(tailNode->next != nullptr){
                tailNode = tailNode->next;
            }
            tailNode->next = node;
        }

        ++ m_size;
    }

    void pop_back(){                                // 移除链表尾部的元素
        if(m_head == nullptr){
            return;
        }

        if(m_size == 1){
            delete m_head;
            m_head = nullptr;
            -- m_size;
            return;
        }

        Node* preNode = m_head;
        Node* tailNode = preNode->next;
        while(tailNode->next != nullptr){
            preNode = tailNode;
            tailNode = tailNode->next;
        }
        preNode->next = nullptr;
        delete tailNode;

        -- m_size;
    }

    void operator=(const ForwardList& other){       // 重载赋值运算符
        {
            Node* cur = m_head;
            Node* next;
            while(cur != nullptr){
                next = cur->next;
                delete cur;
                cur = next;
            }
        }

        m_head = nullptr;
        m_size = other.size();

        if(other.empty()){
            return;
        }

        m_head = new Node(other.head()->data);
        if(other.size() == 1){
            return;
        }
        
        Node* preNode = m_head;
        Node* selfNode;
        Node* otherNode = other.head()->next;
        while(otherNode != nullptr){
            selfNode = new Node(otherNode->data);
            preNode->next = selfNode;
            preNode = preNode->next;
            otherNode = otherNode->next;
        }
    }

    // for pratice and it doesn't
    void insert(int index, T elem){}                // 向指定位置插入元素

    void remove(int index){}                        // 删除指定位置的元素

    void set(int index, T elem){}                   // 修改指定位置的元素

    T& get(int index) const {}                      // 获取指定位置的元素

    // for unit test
    void print(const char* name) const {
        std::cout << name << "(ForwardList): size = " << size() << '\n';
        std::cout << "data = ";
        Node* curNode = m_head;
        while(curNode != nullptr){
            std::cout << curNode->data << " -> ";
            curNode = curNode->next;
        }
        std::cout << "nullptr" << std::endl;
    }

private:
    Node* m_head;
    int m_size;
};

#endif // FORWARDLIST_H_