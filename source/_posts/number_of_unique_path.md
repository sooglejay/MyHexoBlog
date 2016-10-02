---
title: 动态规划理解（1）Number Of Unique Paths
---
Given a M X N matrix with initial position at top-left corner, find the number of possible unique paths to reach the bottom right corner of the grid from the initial position.


NOTE: Possible moves can be either down or right at any point in time, 


    i.e., we can move to matrix[i+1][j] or matrix[i][j+1] from matrix[i][j].
 
 

Input: 

The first line contains an integer T, depicting total number of test cases. 
Then following T lines contains an two integers A and B depicting the size of the grid.

Output:

Print the number of unique paths to reach bottom-right corner from the top-left corner.


Constraints:

1 ≤ T ≤ 30
1 ≤ M ≤ 15
1 ≤ N ≤ 15

Example:

Input
2
2 2
3 4
Output
2
10

**For More Examples Use Expected Output**

## 思路
k个元素为一组 做 reverse 操作


### 代码如下


    #include <stdio.h>
	int numberOfPaths(int m, int n)
	{
    	// Create a 2D table to store results of subproblems
	    int count[m][n];
    	int i,j;
    
	    // Count of paths to reach any cell in first column is 1
    	for (i = 0; i < m; i++)
        	count[i][0] = 1;
    
	    // Count of paths to reach any cell in first column is 1
    	for (j = 0; j < n; j++)
        	count[0][j] = 1;
    
	    // Calculate count of paths for other cells in bottom-up manner using
    	// the recursive solution
	    for (i = 1; i < m; i++)
    	{
        	for (j = 1; j < n; j++)
            
            	// By uncommenting the last part the code calculatest he total
	            // possible paths if the diagonal Movements are allowed
    	        count[i][j] = count[i-1][j] + count[i][j-1]; //+ count[i-1][j-1];
        
	    }
    	return count[m-1][n-1];
	}
	int main(){
    	int T;
	    scanf("%d",&T);
    	int i=0,M,N;
	    for(i=0;i<T;i++){
    	    scanf("%d",&M);
        	scanf("%d",&N);
	        int b= numberOfPaths(M,N);
    	    printf("%d\n",b);
	    }
	}
	
	
	
要理解上面的table 需逆向的想象 数组的生长方向，也就是从右向左，从下往上的生长，就能够理解了

    [i][j] = [i-1][j]+[i][j-1]
    
    [0][0]是右下角的元素，[m-1][n-1]是左上角的元素，这就是自底向下的的动态规划算法，没什么神秘的，只是在编程的时候，思维转换需要些功夫，特别注意是逆向的考虑！    
    简而言之：动态规划 ＝ 递归＋逆向思维
    
    逆向思维如何做到？ 就是先顺着想明白，再反向一步一步退回去
