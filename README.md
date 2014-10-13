Data Structures and Algorithms
==========
`Data Structure` `Sort` `Search` `Permutation` `Combination`

> All **classical**, **beautiful**, and **amazing** algorithms of computer science

###Sort
- **Bubble sort** - exchanging values.
- **Selection sort** - Selection.
- **Insertion sort** - Insertion.
- **Merge sort** - Merge.
- **Inplace merge sort** - Inplace merge.
- **Quick sort** - Quick.
- **Heap sort** - Heap.

#### Analysis of sort algorithms
| Name              | Best      | Average  | Worst         | Memory      | Stable   |   
|:-----------------:|:---------:|:--------:|:-------------:|:-----------:|:--------:|
| Bubble sort       | n         |<img src="http://chart.googleapis.com/chart?cht=tx&chl=\\n^2">|<img src="http://chart.googleapis.com/chart?cht=tx&chl=\\n^2">| 1           | Yes      |
| Selection sort    |<img src="http://chart.googleapis.com/chart?cht=tx&chl=\\n^2">|<img src="http://chart.googleapis.com/chart?cht=tx&chl=\\n^2">|<img src="http://chart.googleapis.com/chart?cht=tx&chl=\\n^2">| 1           | No       | 
| Insertion sort    | n         |<img src="http://chart.googleapis.com/chart?cht=tx&chl=\\n^2">|<img src="http://chart.googleapis.com/chart?cht=tx&chl=\\n^2">| 1           | Yes      | 
| Merge sort        | nlogn     | nlogn    | nlogn         | `worst`   n | Yes      | 
| Inplace merge sort| --        | --       |<img src="http://chart.googleapis.com/chart?cht=tx&chl=\\n^2">| 1           | Yes      |
| Quick sort        | nlogn     | nlogn    |<img src="http://chart.googleapis.com/chart?cht=tx&chl=\\n^2">| `average` logn <br> `worst` n | `typical` No|
| Heap sort         | nlogn     | nlogn    | nlogn         | 1           | No       |

### Permutations and Combinations
- **full_permutation** - recursive method.
- **combination** - recursive method.

----------

数论
====
- Euclidean algorithm [wiki](http://en.wikipedia.org/wiki/Euclidean_algorithm) - 欧几里得算法（辗转相除法）An algorithm for the Greatest Common Divisor (GCD).
- Extended Euclidean algorithm [wiki](http://en.wikipedia.org/wiki/Extended_Euclidean_algorithm) - 扩展欧几里得算法 [维基](http://zh.wikipedia.org/wiki/%E6%89%A9%E5%B1%95%E6%AC%A7%E5%87%A0%E9%87%8C%E5%BE%97%E7%AE%97%E6%B3%95)

字符串处理
==========
- Edit Distance - 字符串编辑距离 [csdn](http://blog.csdn.net/huaweidong2011/article/details/7727482) [Ref](http://www.csse.monash.edu.au/~lloyd/tildeAlgDS/Dynamic/Edit/)

Others
======
- 线段相交 - 参考算法导论
- 八皇后问题
- Bitmap - 位图

