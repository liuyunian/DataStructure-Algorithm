#include "List/Deque.h"

int main(){
    Deque<int> deque(5);                // test ctor() with one param
    deque.print("deque");               // test capacity() size()

    deque.push_front(1);                // test push_front()
    deque.print("deque");

    deque.insert(0, 0);                 // test insert()     
    deque.print("deque");

    for(int i = 0; i <= 10; ++ i){
        deque.push_back(i);             // test push_back() resize()
    }
    deque.print("deque");

    Deque<int> deque2;                  // test default ctor()
    deque2.print("deque2");
    deque2 = deque;                     // test operator=()
    deque2.print("deque2");

    Deque<int> deque3 = deque;          // test cp ctor()
    deque3.print("deque3");

    std::cout << "deque[0] = " << deque.front() << std::endl;     // test front()
    std::cout << "deque[1] = " << deque[1] << std::endl;          // test operator[]
    std::cout << "deque[2] = " << deque.at(2) << std::endl;       // test at()
    std::cout << "deque.back() = " << deque.back() << std::endl;  // test back()

    deque.pop_front();                  // test pop_front()
    deque.print("deque");

    deque.pop_back();                   // test pop_back()
    deque.print("deque");

    deque.remove(0);                    // test remove
    deque.print("deque");

    for(int i = 10; i <= 20; ++ i){     // test resize()
        deque.push_back(i);
    }
    deque.print("deque");

    for(int i = 1; i <= 15; ++ i){
        deque.pop_back();
        deque.print("deque");
    }
    
    return 0;
}
