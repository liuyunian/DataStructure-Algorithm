#include "List/ForwardList.h"

int main(){
    ForwardList<int> fl;            // test default ctor
    fl.print();

    for(int i = 10; i >= 0; -- i){
        fl.push_front(i);           // test push_front
        fl.print();
    }

    ForwardList<int> fl2(fl);       // test copy ctor
    fl2.print();

    ForwardList<int> fl3;
    fl3.push_front(0);
    fl3.push_front(1);
    fl3 = fl;                       // test operator=
    fl3.print();

    for(int i = 0; i < 5; ++ i){
        fl.pop_front();             // test pop_front
        fl.print();
    }

    return 0;
}