#include "List/List.h"

int main(){
    List<int> list;                     // test default ctor
    list.print("list");

    for(int i = 9; i >= 0; -- i){
        list.push_front(i);             // test push_front
        list.print("list");
    }

    List<int> list2(list);              // test copy ctor
    list2.print("list2");

    List<int> list3;
    list3.push_front(0);
    list3.push_front(1);
    list3 = list;                       // test operaotr=
    list3.print("list3");

    for(int i = 0; i < 10; ++ i){
        list.pop_front();               // test pop_front
        list.print("list");
    }

    for(int i = 0; i < 5; ++ i){
        list.push_back(i);              // test push_back
        list.print("list");
    }

    for(int i = 0; i < 5; ++ i){        // test pop_back
        list.pop_back();
        list.print("list");
    }

    return 0;
}