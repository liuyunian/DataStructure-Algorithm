#ifndef BINARYSEARCH_H_
#define BINARYSEARCH_H_

namespace Search {

/**
 * @brief 循环方式实现二分查找
 * @return 查找到了返回对应的index，否则返回-1
*/
template <typename T>
int binary_search(T array[], int size, T target){
    int left = 0;
    int right = size - 1;
    int middle;
    while(left <= right){
        middle = left + (right - left) / 2;
        if(target == array[middle]){
            return middle;
        }
        else if(target < array[middle]){
            right = middle - 1;
        }
        else{
            left = middle + 1;
        }
    }

    return -1;
}

/**
 * @brief 递归方式实现二分查找
 * @return 查找到了返回对应的index，否则返回-1
*/
template <typename T>
int binary_search(T array[], int left, int right, T target){
    if(left > right){
        return -1;
    }

    int middle = left + (right - left) / 2;
    if(target == array[middle]){
        return middle;
    }
    else if(target < array[middle]){
        binary_search(array, left, middle - 1);
    }
    else{
        binary_search(array, middle + 1, right);
    }
}

} // namespace Search

#endif // BINARYSEARCH_H_