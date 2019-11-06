#ifndef LIST_H_
#define LIST_H_

#include <iostream>

#include <tools/base/copyable.h>
#include <tools/base/noncopyable.h>

template <typename T>
class List : copyable {
public:
    struct Node {
        T data;
        Node* pre;
        Node* next;

        Node(T elem) : data(elem), pre(nullptr), next(nullptr){}
    };

    List() : m_head(nullptr), m_size(0){}                           // 默认构造函数

    List(const List& other) :                                       // 拷贝构造函数
        m_head(nullptr),
        m_size(other.size())
    {
        copy(other);
    }

    ~List(){
        clear();
    }

    Node* head() const {
        return m_head;
    }

    int size() const {
        return m_size;
    }

    bool empty() const {
        return m_size == 0;
    }

    void push_front(T elem){                                        // 向链表头部添加元素
        Node* node = new Node(elem);
        if(m_head == nullptr){
            m_head = node;
            m_head->next = m_head;
            m_head->pre = m_head;
        }
        else{
            Node* tailNode = m_head->pre;
            node->next = m_head;
            node->pre = tailNode;
            m_head->pre = node;
            tailNode->next = node;
            m_head = node;
        }
        
        ++ m_size;
    }

    void pop_front(){                                               // 移除链表头部的元素
        if(m_head == nullptr){
            return;
        }

        if(m_size == 1){
            delete m_head;
            m_head = nullptr;
        }
        else{
            Node* nextNode = m_head->next;
            Node* tailNode = m_head->pre;

            tailNode->next = nextNode;
            nextNode->pre = tailNode;
            delete m_head;
            m_head = nextNode;
        }

        -- m_size;
    }

    void push_back(T elem){                                         // 向链表尾部添加元素
        Node* node = new Node(elem);
        if(m_head == nullptr){
            m_head = node;
            m_head->next = m_head;
            m_head->pre = m_head;
        }
        else{
            Node* tailNode = m_head->pre;
            node->next = m_head;
            node->pre = tailNode;
            tailNode->next = node;
            m_head->pre = node;
        }

        ++ m_size;
    }

    void pop_back(){                                                // 移除链表头部的元素
        if(m_head == nullptr){
            return;
        }

        if(m_size == 1){
            delete m_head;
            m_head = nullptr;
        }
        else{
            Node* tailNode = m_head->pre;
            tailNode->pre->next = m_head;
            m_head->pre = tailNode->pre;
            delete tailNode;
        }

        -- m_size;
    }

    void operator=(const List& other){
        clear();
        m_head = nullptr;
        m_size = other.size();

        copy(other);
    }

    T& front() const {
        return m_head->data;
    }

    T& back() const {
        return m_head->pre->data;
    }

    // for pratice and it doesn't
    void insert(int index, T elem){}                // 向指定位置插入元素

    void remove(int index){}                        // 删除指定位置的元素

    void set(int index, T elem){}                   // 修改指定位置的元素

    T& get(int index) const {}                      // 获取指定位置的元素

    // for unit test
    void print(const char* name) const {
        std::cout << name << "(List): size = " << m_size << '\n';
        std::cout << "data: ";
        if(m_size == 0){
            std::cout << "nullptr" << std::endl;
            return;
        }

        Node* node = m_head;
        for(int i = 0; i < m_size; ++ i){
            std::cout << node->data << " <=> ";
            node = node->next;
        }
        std::cout << m_head->data << std::endl;
    }

private:
    void clear(){
        Node* cur = m_head;
        Node* next;
        for(int i = 0; i < m_size; ++ i){
            next = cur->next;
            delete cur;
            cur = next;
        }
    }

    void copy(const List& other){
        if(m_size == 0){
            return;
        }

        m_head = new Node(other.head()->data);
        Node* preNode = m_head;
        Node* selfNode;
        Node* otherNode = other.head()->next;
        for(int i = 1; i < m_size; ++ i){
            selfNode = new Node(otherNode->data);
            selfNode->pre = preNode;
            preNode->next = selfNode;
            preNode = selfNode;

            otherNode = otherNode->next;
        }

        preNode->next = m_head;
        m_head->pre = preNode;
    }

private:
    Node* m_head;
    int m_size;
};

#endif // LIST_H_