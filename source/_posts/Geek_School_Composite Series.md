---
title: Composite Series
---
Given a number N, print all the composite numbers less than or equal to N. The number should be printed in ascending order.

Input:
The first line contain an Integer T denoting the number of  test cases . Then T test cases follow. Each test case consist of an single integer N.

Output:
Print all the composite Number form 0 to N.

Constraints:

1 ≤ T ≤ 50
4 ≤ N ≤ 10000

Example:
Input:
2
10
6
Output:
4 6 8 9 10
4 6

**For More Examples Use Expected Output**

## 题目大意
###输入
第一行输入个数T，表示接下来有T组输入N

接下来有T组输入，每一组输入是一个数字
###输出
一共有T行输出，每一行输出对应上面每一组输入

计算小于N的所有合数

###注   
不是素数的自然数就是合数，素数是指只能被1 和自身整除的自然数。2是最小的素数，1既不是素数也不是合数


### 代码如下

``` 
#include <stdio.h>
#include <string.h>
#include <math.h>
int isPrime(int n){
    if (n==2) {
        return 1;
    }
    int s = sqrt(n);
    int i;
    for(i=2;i<=s;i++){
        if (n%i==0) {
            return 0;
        }
    }
    return 1;
}
int main() {
    int T,i,j,N;
    scanf("%d",&T);
    int A[T][10000];
    int z=0;
    for (j=0; j<T; j++) {
        scanf("%d",&N);
        for(i=2;i<=N;i++){
            if (!isPrime(i)) {
                *(A[j]+z) = i;
                z++;
                
            }
        }
         *(A[j]+z) = -1;
        z++;
    }
    for(j=0;j<T ; j++) {
        i=0;
        while (*(A[j]+i)!=-1) {
            if (*(A[j]+i)==0) {
                i++;
                continue;
            }
            printf("%d ",*(A[j]+i));
            i++;
            if(*(A[j]+i)==-1){
                printf("\n");
                break;
            }
        }
    }
    return 0;
}
```