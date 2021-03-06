插入排序(Insertion Sort)
=========================

## 1. 直接插入排序(Straight Insertion Sort)
对于数组a[n]，将后n-1个记录依次插入到前面已经排好序的有序表中。
特点：当序列中的记录“基本有序”或n值较小时，直接插入排序是最佳的排序方法，因此常将它和快排、归并排序等结合在一起使用。

## 2. 折半插入排序(Binary Insertion Sort)
为了减少比较(comparison)次数，在有序表中的“查找”操作可以利用“折半查找”(Binary Search)来实现。

## 3. 2-路插入排序
在折半插入排序的基础上改进，目的是减少排序过程中“移动”记录的次数，但需要n个记录的辅助空间。

## 4. 希尔排序(Shell's Sort)
即缩小增量排序(Diminishing Increment Sort)，是一种时间效率较高的插入排序。
基本思想：先将整个待排记录序列分割成为若干子序列分别进行直接插入排序，带整个序列“基本有序”时，再对全体记录进行一次直接插入排序。
