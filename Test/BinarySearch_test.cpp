#include "Search/BinarySearch.h"
#include "Sort/MergeSort.h"
#include "Test/TestHelper/SortHelper.h"

int main(){
    int* array;
    int random; // 记录要查找的数，随机一个[0, size]范围内的整数
    int index;  // 查找到的结果
    for(int size = 10; size <= 1000; size *= 10){
        array = SortHelper::generate_random_nonrepeat_array(size, 0);
        Sort::merge_sort(array, 0, size-1);
        
        random = SortHelper::generate_random_number(0, size);
        index = Search::binary_search(array, size, random);
        std::cout << "array[" << index << "] = " << random << std::endl;
        delete[] array;
    }

    return 0;
}