# 查找

## 查找表
在一个数据集合上查找想要的内容，这个数据集合就是查找表  
查找表可以分为：  
* 静态查找表：只做查找工作，查找过程中不会去改变查找表中的数据
* 动态查找表：在查找过程中会插入不存在的数据元素，或者删除特定的元素，也就是在查找过程中会去改变查找表

## 存储结构
查找表存储在不同的数据结构上查找效率是不一样的  

| 数据结构 | 查找 | 插入 | 删除 |
| --- | --- | --- | --- |
| 普通数组 | O(n) | O(n) | O(n) |
| 顺序数组 | O(logn) | O(n) | O(n) |
| 二分查找树 | O(logn) | O(logn) | O(logn) |

对于静态查找表，以顺序数组存储，可以采用二分查找法进行高效的查找操作  
对于动态查找表，更多的采用二分查找树进行存储
哈希表（散列表）也可以解决一些查找问题

## 查找方式
### 顺序查找
最简单暴力的查找方式，思路就是遍历整个数据集合，最好的情况下时间复杂度为O(1), 最坏的情况下时间复杂度为O(n), 平均时间复杂度为O(N)
适用于静态查找表，对表中的数据没有要求，在数据量很小的情况下可以使用顺序查找

### [二分查找]()