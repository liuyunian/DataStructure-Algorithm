#ifndef MERGESORT_H_
#define MERGESORT_H_

namespace Sort {

template <typename T>
void merge_sort(T array[], int left, int right){
    if(left >= right){
        return;
    }

    int middle = (left+right) / 2;
    merge_sort(array, left, middle);
    merge_sort(array, middle+1, right);

    // merge
    T tmp[right-left+1];
    for(int i = left; i <= right; ++ i){
        tmp[i-left] = array[i];
    }

    int i = left, j = middle+1;
    for(int k = left; k <= right; ++ k){
        if(i > middle){                                     // [left, middle]区间的数据都已经遍历结束了
            array[k] = tmp[j-left];
            ++ j;
            continue;
        }

        if(j > right){                                      // [middle+1, right]区间的数据都已经遍历结束了
            array[k] = tmp[i-left];
            ++ i;
            continue;
        }

        if(tmp[i-left] < tmp[j-left]){
            array[k] = tmp[i-left];
            ++ i;
        }
        else{
            array[k] = tmp[j-left];
            ++ j;
        }
    }
}

} // namespace Sort

#endif // MERGESORT_H_