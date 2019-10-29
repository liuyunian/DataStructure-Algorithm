#include "Sort/SortTestHelper.h"

int main(){
    int* array;
    for(int size = 10; size <= 10000; size *= 10){
        array = SortTestHelper::generate_random_array(size, 0, size);
        SortTestHelper::print_array(array, size);
        delete[] array;
    }

    return 0;
}