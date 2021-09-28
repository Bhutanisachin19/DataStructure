//factorial of a number using recursion and sum of  numbers from n to 1



#include<stdio.h>

long fact(int n)
{
    //Base case
    if(n==0)
        return 1;

    return n * fact(n-1); //solution
}


int sum(int n)
{
    if(n==1)
        return 1;

    return n + sum(n-1);
}

void main()
{
    int number;
    printf("Enter a number in greater than 0 \n");
    scanf("%d",&number);

    long fact_n = fact(number);
    printf("factorial of %d is %d \n",number , fact_n);

    int sum_n = sum(number);
    printf("sum of all digits from %d to 1 is %d \n",number , sum_n);
}


