#ifndef HELPER_H_
#define HELPER_H_

#include <iostream>

#include <stdlib.h> // srand rand
#include <time.h>   // time
#include <assert.h> // assert

namespace SortTestHelper {

/**
 * 生成有n个元素的随机数组
 * 每个元素的随机范围是[left, right]
*/
int* generate_random_array(int size, int left, int right){
    assert(left <= right);

    int *array = new int[size];
    srand(time(NULL));
    for(int i = 0; i < size; ++i){
        array[i] = rand() % (right - left + 1) + left;
    }

    return array;
}

void print_array(int array[], int size){
    for(int i = 0; i < size; ++ i){
        std::cout << array[i] << " ";
    }

    std::cout << std::endl;
}

} // namespace SortTestHelper

#endif // HELPER_H_