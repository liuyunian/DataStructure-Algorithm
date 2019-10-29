#include "Sort/MergeSort.h"
#include "Sort/SortTestHelper.h"

int main(){
    int* array;
    for(int size = 10; size <= 10000; size *= 10){
        array = SortTestHelper::generate_random_array(size, 0, size);
        Sort::merge_sort(array, 0, size-1);
        SortTestHelper::print_array(array, size);
        delete[] array;
    }

    return 0;
}