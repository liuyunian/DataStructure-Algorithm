#include "List/ForwardList.h"

int main(){
    ForwardList<int> fl;            // test default ctor
    fl.print("fl");

    for(int i = 9; i >= 0; -- i){
        fl.push_front(i);           // test push_front
        fl.print("fl");
    }

    ForwardList<int> fl2(fl);       // test copy ctor
    fl2.print("fl2");

    ForwardList<int> fl3;
    fl3.push_front(0);
    fl3.push_front(1);
    fl3 = fl;                       // test operator=
    fl3.print("fl3");

    for(int i = 0; i < 10; ++ i){
        fl.pop_front();             // test pop_front
        fl.print("fl");
    }

    for(int i = 0; i < 5; ++ i){
        fl.push_back(i);            // test push_back
        fl.print("fl");
    }

    for(int i = 0; i < 5; ++ i){
        fl.pop_back();              // test pop_back
        fl.print("fl");
    }

    return 0;
}