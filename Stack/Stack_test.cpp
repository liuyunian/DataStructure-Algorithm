#include "Stack/Stack.h"
#include "List/List.h"

int main(){
    Stack<int> stack;                   // test Deque stack
    for(int i = 0; i < 5; ++ i){
        stack.push(i);                  // test push
        stack.print("stack");
    }

    while(!stack.empty()){
        std::cout << "top = " << stack.top() << std::endl; // test top
        stack.pop();                    // test pop
        stack.print("stack");
    }

    Stack<int, List<int>> listStack;        // test List stack
    for(int i = 0; i < 5; ++ i){
        listStack.push(i);                  // test push
        listStack.print("listStack");
    }

    while(!listStack.empty()){
        std::cout << "top = " << listStack.top() << std::endl; // test top
        listStack.pop();                    // test pop
        listStack.print("stack");
    }

    return 0;
}