#include <Queue/CircleQueue.h>

int main(){
    CircleQueue<int> cq;                                    // test default ctor
    cq.print("cq");

    for(int i = 0; i < 10; ++ i){
        cq.push(i);                                         // test push
        cq.print("cq");
    }

    std::cout << "front = " << cq.front() << std::endl;     // test front
    std::cout << "back = " << cq.back() << std::endl;       // test back

    while(!cq.empty()){
        cq.pop();                                           // test pop
        cq.print("cq");
    }

    return 0;
}



