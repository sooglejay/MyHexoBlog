---
title: 数学问题的解题思路（等量关系） 
---

### 等量关系
不论神马问题，一定存在某种等量关系，这跟能量守恒定律的哲学思想是一致的！嗯...数学中的一些定理定律确实很多充满了哲学意味，这也是为什么非常多的数学家或物理学家也是哲学家的原因，比如亚里士多德、苏格拉底、康德，等等。能量是守恒的！事物的一种状态转变为另一种状态后，伴随的能量的转移，但是能量始终是守恒的，不多也不少！宇宙中的能量从一出生起就没有增加也没有减少，只是它的能量大到目前算不出来。不扯了，看问题

```
There are n bikes and each can cover 100 km when fully fueled. What is the maximum amount of distance you can go using n bikes? You may assume that all bikes are similar and a bike takes 1 litre to cover 1 km.

The output may contain decimal value but print the integer value of the float value obtained.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N.

Output:

Print the maximum amount of distance. 

Constraints:

1 ≤ T ≤ 20
1 ≤ N ≤ 50

Example:

Input
2
1
2

Output

100

150
 

**For More Examples Use Expected Output**
```

在做这个问题时，有一种在做小学数学题的赶脚...


```
大意是，一辆自行车在满油状态下可以跑100km，且每1km消耗1升油。问：给你n辆自行车，你最多能跑多远？（注意，中途可以丢掉自行车）
```
直接给方法了

    这里的等量关系是，不管你跑多远，所有自行车的油总量是不变的，只是消耗了的油转换为了动能等等其他形式的能量。

比如，如果n＝1，那么只能跑 100km

如果 n ＝ 2

那么 设 在跑了 x km 时 把它的油给另一辆自行车加满，再丢掉该辆没油的自行车
(这是核心技巧：牺牲小我，成全大家)

```
等量关系：  2*100 ＝ 2x ＋ 100     
```
等量关系如下


    油总量 ＝ 已经消耗的油 + 剩余的油总量


好了，有规律了

    3辆   3 * 100 ＝ 3x ＋ 2*100 
    
    4辆   4*100 ＝ 4x ＋ 3*100 

    5辆   5*100 ＝ 5x ＋ 4*100 

    6辆   6*100 ＝ 6x ＋ 5*100 

	...
	
	n辆   n*100 = nx + (n-1)*100 

注意上面只是第一次 丢自行车（牺牲小我，成全大家）

    也就是说，第一次跑了 x km，还剩下 n－1 辆自行车。好了，这是一个递归。

老司机只能带你到这儿了



