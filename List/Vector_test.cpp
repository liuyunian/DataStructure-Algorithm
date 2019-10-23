#include "List/Vector.h"

int main(){
    Vector<int> v(5);               // test ctor() with one param
    v.print();                      // test capacity() size()

    Vector<int> v2;                 // test default ctor()
    v2.print();

    v.push_front(1);               // test push_front()
    v.print();

    v.insert(0, 0);                // test insert()     
    v.print();

    for(int i = 0; i <= 10; ++ i){
        v.push_back(i);            // test push_back() resize()
    }
    v.print();

    v2 = v;                         // test operator=()
    v.print();

    Vector<int> v3 = v;            // test cp ctor()
    v3.print();

    std::cout << "v[0] = " << v.front() << std::endl;     // test front()
    std::cout << "v[1] = " << v[1] << std::endl;          // test operator[]
    std::cout << "v[2] = " << v.at(2) << std::endl;       // test at()
    std::cout << "v.back() = " << v.back() << std::endl;  // test back()

    v.pop_front();          // test pop_front()
    v.print();

    v.pop_back();           // test pop_back()
    v.print();

    v.remove(0);            // test remove
    v.print();

    int index = v.find(5);  // test find()
    std::cout << "find index = " << index << std::endl;

    for(int i = 10; i <= 20; ++ i){  // test resize()
        v.push_back(i);
    }
    v.print();

    for(int i = 1; i <= 15; ++ i){
        v.pop_back();
        v.print();
    }
    
    return 0;
}
