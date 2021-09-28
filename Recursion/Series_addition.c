// print numbers and there sum till n using recursion
// eg 1+2+3+4+5=15

#include<stdio.h>

int series(int n)
{
    int s;
    if(n==0)
        return;

    s=(n + series(n-1));
    printf("%d + ",n);
    return s;
}

void main()
{
    int num,sum;
    printf("Enter a number \n");
    scanf("%d",&num);
    sum = series(num);

    printf("\b\b = %d \n",sum);
}
