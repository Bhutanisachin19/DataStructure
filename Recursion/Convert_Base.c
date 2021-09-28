// convert to hexa octa and binary using recursion

#include<stdio.h>

void toBinary(int n)
{
    if(n==0)
        return;

    toBinary(n/2);
    printf("%d",n%2);
}

//to octa and hexa depending on 2nd argument
void convertBase(int n , int base)
{
    int remainder;

    if(n==0)
        return;

    convertBase(n/base , base);
    remainder = n%base;

    if(remainder<10)
        printf("%d",remainder);
    else
        printf("%c",remainder-10+ 'A');
}

main()
{
    toBinary(19);

}
