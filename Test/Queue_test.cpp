#include "Queue/Queue.h"
#include "List/List.h"

int main(){
    Queue<int> queue;                   // test Deque Queue
    queue.print("queue");

    for(int i = 0; i < 5; ++ i){
        queue.push(i);                  // test push
        queue.print("queue");
    }

    std::cout << "front = " << queue.front() << std::endl;  // test front
    std::cout << "back = " << queue.back() << std::endl;    // test back

    while(!queue.empty()){
        queue.pop();                    // test pop
        queue.print("queue");
    }

    Queue<int, List<int>> listQueue;    // test List Queue
    for(int i = 0; i < 5; ++ i){
        listQueue.push(i);                  // test push
        listQueue.print("listQueue");
    }

    std::cout << "front = " << listQueue.front() << std::endl;  // test front
    std::cout << "back = " << listQueue.back() << std::endl;    // test back

    while(!listQueue.empty()){
        listQueue.pop();                    // test pop
        listQueue.print("listQueue");
    }

    return 0;
}