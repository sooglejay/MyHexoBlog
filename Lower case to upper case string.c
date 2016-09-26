/**
 Given a string containing only lowercase letters, generate a string with the same letters, but in uppercase.
 
 Input:
 
 The first line of input contains a single integer T denoting the number of test cases. Then T test cases follow. Each test case consist of one line. The first line of each test case consists of a string.
 
 Output:
 
 Corresponding to each test case, in a new line, print the string in uppercase.
 
 Constraints:
 
 1 ≤ T ≤ 100
 1 ≤ string length ≤ 50
 
 Example:
 
 Input
 2
 geeks
 geeksforgeeks
 
 Output
 GEEKS
 
 GEEKSFORGEEKS
 
 **For More Examples Use Expected Output**
 */
#include<stdio.h>
int main(){
    int T;
    scanf("%d",&T);
    int i,j;
    char array[50];
    for(i=0;i<T;i++){
        scanf("%s",array);
        j=0;
        while(array[j]!='\0'){
            array[j] = array[j]-32;
            j++;
        }
        j=0;
        printf("%s\n",array);
        
    }
    return 0;
}