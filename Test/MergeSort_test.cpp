#include "Sort/MergeSort.h"
#include "TestHelper/TestHelper.h"

int main(){
    int* array;
    for(int size = 10; size <= 1000; size *= 10){
        array = TestHelper::generate_random_array(size, 0, size);
        Sort::merge_sort(array, 0, size-1);
        TestHelper::print_array(array, size);
        delete[] array;

        array = TestHelper::generate_random_nonrepeat_array(size, 0);
        Sort::merge_sort(array, 0, size-1);
        TestHelper::print_array(array, size);
        delete[] array;
    }

    return 0;
}