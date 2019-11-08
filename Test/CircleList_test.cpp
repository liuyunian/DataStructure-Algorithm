#include "List/CircleList.h"

int main(){
    CircleList<int> cl;                  // test default ctor
    cl.print("cl");

    for(int i = 9; i >= 0; -- i){
        cl.push_front(i);               // test push_front
        cl.print("cl");
    }

    CircleList<int> cl2(cl);            // test copy ctor
    cl2.print("cl2");

    CircleList<int> cl3;
    cl3.push_front(0);
    cl3.push_front(1);
    cl3 = cl;                           // test operator=
    cl3.print("cl3");

    for(int i = 0; i < 10; ++ i){
        cl.pop_front();                 // test pop_front
        cl.print("cl");
    }

    for(int i = 0; i < 5; ++ i){
        cl.push_back(i);                // test push_back
        cl.print("cl");
    }

    for(int i = 0; i < 5; ++ i){
        cl.pop_back();                  // test pop_back
        cl.print("cl");
    }

    return 0;
}