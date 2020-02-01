#include "Sort/MergeSort.h"
#include "Test/TestHelper/SortHelper.h"

int main(){
    int* array;
    for(int size = 10; size <= 1000; size *= 10){
        array = SortHelper::generate_random_array(size, 0, size);
        Sort::merge_sort(array, 0, size-1);
        SortHelper::print_array(array, size);
        delete[] array;

        array = SortHelper::generate_random_nonrepeat_array(size, 0);
        Sort::merge_sort(array, 0, size-1);
        SortHelper::print_array(array, size);
        delete[] array;
    }

    return 0;
}