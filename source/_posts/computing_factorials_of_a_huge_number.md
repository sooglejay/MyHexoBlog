---
title: Computing Factorials of A Huge Number 
---

Hello @all,

As in MARCH13 contest we needed to use primary school arithmetics once again, and as it is a topic that comes up quite frequentely here in the forums thanks to this problem, and also, as I don't see a complete and detailed tutorial on this topic here, I decided I'd write one before my Lab class at university :P (spending free time with Codechef is always a joy!!)

Some preliminary experiences with C
If we want to implement a factorial calculator efficientely, we need to know what we are dealing with in the first place...

Some experiences in computing factorials iteratively with the following code:

	#include <stdio.h>

	long long int factorial(int N)
	{
    	long long ans = 1;
	    int i;
    	for(i=1; i <= N; i++)
	    ans *= i;
    	return ans;
	}

	int main()
	{
    	int t;
	    for(t=1; t <= 21; t++)
    	{
        	printf("%lld\n", factorial(t));
	    }
    	return 0;
	}

will produce the following output on Ideone:

```
1
2
6
24
120
720
5040
40320
362880
3628800
39916800
479001600
6227020800
87178291200
1307674368000
20922789888000
355687428096000
6402373705728000
121645100408832000
2432902008176640000
-4249290049419214848
```
So, we can now see that even when using the long long data type, the maximum factorial we can expect to compute correctly, is only 20!

When seen by this point of view, suddenly, 100! seems as an impossible limit for someone using C/C++, and this is actually only partially true, such that we can say:

It is impossible to compute factorials larger than 20 when using built-in data types.

However, the beauty of algorithms arises on such situations... After all, if long long data type is the largest built-in type available, how can people get AC solutions in C/C++? (And, as a side note, how the hell are those "magic" BigNum and variable precision arithmetic libraries implemented?).

The answer to these questions is surprisingly and annoyingly "basic" and "elementar", in fact, we shall travel back to our primary school years and apply what was taught to most of us when we were 6/7/8 years old.

I am talking about doing all operations by hand!!

The underlying idea behind long operations and how to map it into a programming language

12*11 = 132

Any programming language will tell you that. But, so will any 8 year old kid that's good with numbers. But, the kid's way of telling you such result is what we are interested in:

Here's how he would do it:

       12
     x 11
   ---------
       12
     +12
  ----------
      132
But, why is this idea way more interesting than simply doing it straighforwardly? It even looks harder and more error-prone... But, it has a fundamental property that we will exploit to its fullest:

The intermediate numbers involved on the intermediate calculations never exceed 81

This is because it is the largest product possible of two 1-digit numbers (9*9 = 81), and these numbers,well, we can deal with them easily!!

The main idea now is to find a suitable data structure to store all the intermediate results and for that we can use an array:

Say int a[200] is array where we can store 200 1-digit numbers. (In fact, at each position we can store an integer, but we will only store 1 digit for each position.)

So, we are making good progress!! We managed to understand two important things:

Primary school arithmetic can prove very useful on big number problems;
We can use all built-in structures and data-types to perform calculations;
Now, comes up a new question:

How can we know the length of such a huge number? We can store an array and 200 positions, but, our big number may have only 100 digits for example.

The trick is to use a variable that will save us, at each moment, the number of digits that is contained in the array. Let's call it m.

Also, since we want only one digit to be stored in every position of array, we need to find a way to "propagate" the carry of larger products to higher digits and sum it afterwards. Let's call the variable to hold the carry, temp.

m -> Variable that contains the number of digits in the array in any given moment;
temp -> Variable to hold the "carry" value resultant of multiplying digits whose product will be larger than 9. (8*9 = 72, we would store 2 on one array position, and 7 would be the "carry" and it would be stored on a different position.)

So, now that we have an idea on how to deal with the multiplications, let's work on mapping it into a programming language.

Coding our idea and one final detail
Now, we are ready to code our solution for the FCTRL2 problem.

However, one last remark needs to be done:

How do we store a number in the array, and why do we store it the way we do?

If after reading this tutorial you look at some of the accepted solutions in C/C++ for this problem, you will see that contestants actually stored the numbers "backwards", for example:

123 would be saved in an array, say a, as:

a = [3,2,1];

This is done such that when the digit by digit calculations are being performed, the "carry" can be placed on the positions of the array with higher index. 

This way, we are sure that carry is computed and placed correctly on the array.

Also, computing the products this way and maintaining the variable, m, allows us to print the result directly, by looping from a[m-1] until a[0].

As an example, I can leave here an implementation made by @upendra1234, that I took the liberty to comment for a better understanding:

    #include<stdio.h>
	int main()
	{
    	int t;
	    int a[200]; //array will have the capacity to store 200 digits.
    	int n,i,j,temp,m,x;
	
    	scanf("%d",&t);
	    while(t--)
    	{
	       	scanf("%d",&n);
	    	a[0]=1;  //initializes array with only 1 digit, the digit 1.
    	   m=1;    // initializes digit counter

           temp = 0; //Initializes carry variable to 0.
	       for(i=1;i<=n;i++)
    	   {
        	    for(j=0;j<m;j++)
            	{
               	   x = a[j]*i+temp; //x contains the digit by digit product
	               a[j]=x%10; //Contains the digit to store in position j
    	           temp = x/10; //Contains the carry value that will be stored on later indexes
        	    }
            	while(temp>0) //while loop that will store the carry value on array.
             	{ 
               		a[m]=temp%10;
              	 	temp = temp/10;
	               m++; // increments digit counter
    	         }
    	   }
           for(i=m-1;i>=0;i--) //printing answer
           printf("%d",a[i]);
           printf("\n");
	    }
    	return 0;
	}

I hope this tutorial can help someone to gain a better understanding of this subject and that can help some people as it is why we are here for :D

Best Regards,

Bruno Oliveira

EDIT: As per @betlista comment, it's also worth pointing out that, since we keep only a single digit at each position on the array, we could have used the data-type char instead of int. This is because internally, a char is actually an integer that only goes in the range 0 - 255 (values used to represent the ASCII codes for all the characters we are used to see). The gains would be only memory-wise.