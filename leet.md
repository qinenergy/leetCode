# Leetcode Solution Memo

## 287 Find the duplicate number

环检测问题： 序列 x_i 定义为 x_i = f(x_{i-1})

如果f从定义域映射到它本身，三种情况。

1. 如果定义域无穷，则序列无限长而且无循环
2. 闭合循环 x_0 = x_i
3. P型循环 x_k = x_{k+t}

因为下标0不可能再次被访问到，所以肯定是P型循环

Floyd 龟兔算法： 给定p型序列，线性时间，常数空间寻找环起点。

算法： c：进入环的链的长度， l为环的长度， 令l‘为大于c的l的倍数的最小值

1. x_{l'} = x_{2 l'}

​     slow = x_j = fast = x_2j, 所以j至少为c，此时已在环中， 而且j是l的倍数。

2. x[slow+c] = x[c]

