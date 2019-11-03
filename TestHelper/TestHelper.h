#ifndef TESTHELPER_H_
#define TESTHELPER_H_

#include <iostream>

#include <stdlib.h> // srand rand
#include <time.h>   // time
#include <assert.h> // assert

namespace TestHelper {

/**
 * 随机生成n个整数（含重复数字）
 * 范围是[left, right]
 * 以数组方式返回
*/
int* generate_random_array(const int size, const int left, const int right){
    assert(left <= right);

    int* array = new int[size];
    srand(time(NULL));
    for(int i = 0; i < size; ++i){
        array[i] = rand() % (right-left+1) + left;
    }

    return array;
}

/**
 * 随机生成n个整数（不含重复数字）
 * 范围[left, left+size-1]
 * 以数组方式返回
*/
int* generate_random_nonrepeat_array(const int size, const int left){
    int* array = new int[size];
    bool* flag = new bool[size];
    for(int i = 0; i < size; ++ i){
        flag[i] = false;
    }

    srand(time(NULL));
    int i = 0;
    int data; // 用来记录随机生成的数
    while(i < size){
        data = rand() % size;
        if(!flag[data]){
            array[i] = data + left;
            flag[data] = true;
            ++ i;
        }
    }

    return array;
}

void print_array(const int array[], const int size){
    for(int i = 0; i < size; ++ i){
        std::cout << array[i] << " ";
    }

    std::cout << "\n####################################" << std::endl;
}

/**
 * @brief 随机生产一个整数
 * @param 范围[left, right]
 * @return 随机生成的整数
*/
int generate_random_number(int left, int right){
    srand(time(NULL));
    return rand() % (right-left+1) + left;
}

} // namespace TestHelper

#endif // TESTHELPER_H_