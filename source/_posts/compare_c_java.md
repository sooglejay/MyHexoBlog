---
title: C和Java在一道简单算法题中的表现
---

### Alone in couple
In a party everyone is in couple except one. People who are in couple have same numbers. Find out the person who is not in couple.

Input:
The first line contains an integer 'T' denoting the total number of test cases. In each test cases, the first line contains an integer 'N' denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array. (N is always odd)


Output:
In each seperate line print number of the person not in couple.


Constraints:
1<=T<=30
1<=N<=500
1<=A[i]<=500
N%2==1


Example:
Input:
1
5
1 2 3 2 1

Output:
3

**For More Examples Use Expected Output**


### Java
    
``` c
    
    import java.util.*;
    import java.lang.*;
    import java.io.*;

    class GFG {
	    public static void main (String[] args) {
		    Scanner scanner = new Scanner(System.in);
            int T = scanner.nextInt();
            int A[] = new int[T];
            int N, i, j;
            int array[] = new int[501];
            for (i = 0; i < T; i++) {
                A[i] = 0;
                N = scanner.nextInt();
                for (j = 0; j < 501; j++) {
                    array[j] = 0;
                }
                for (j = 0; j < N; j++) {
                    int aa=scanner.nextInt();
                    array[aa]++;
                }
                for (j = 0; j < 501; j++) {
                    if (array[j] % 2 == 1) {
                        A[i] = j;
                        break;
                    }
                }
            }
            for(i=0;i<T;i++){
                System.out.println(A[i]);
            }
    	}
    }
```  
 
![img](/img/1.PNG)
  
  
  ### C
  
``` java

    #include <stdio.h>
	#define MAX 501
    int main() {
        int T;
    	scanf("%d",&T);
	    int A[T];
    	int i=0,j,N,temp;
	    int array[MAX];
    	for(;i<T;i++){
        	A[i]=0;
	        j=0;
    	    scanf("%d",&N);
        	for(j=0;j<MAX;j++){
            	array[j]=0;
	        }
    	    for(j=0;j<N;++j){
        	    scanf("%d",&temp);
            	array[temp]++;
	        }
    	    for(j=0;j<MAX;j++){
        	    if(array[j]%2){
            	    A[i] = j;
                	break;
            	}
	        }
    
    	}
	    for(i=0;i<T;i++){
    	    printf("%d\n",A[i]);
    	}
	    return 0;
	}
	
```
![img](/img/2.PNG)
