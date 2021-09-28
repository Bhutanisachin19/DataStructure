//Bubble sort on array

#include<stdio.h>
int* bubble_sort(int arr[],int n)
{
    int i,j,flag,count=1;

    for(i=n-2;i>=0;i--)
    {
        flag = 0;
        for(j=0;j<=i;j++)
        {
            if(arr[j] > arr[j+1])
            {
                //swap
                count++;
                flag = 1;
                arr[j] = arr[j] + arr[j+1];
                arr[j+1] = arr[j] - arr[j+1];
                arr[j] = arr[j] - arr[j+1];
            }
        }

        if(flag == 0 )
            break;

    }
    printf("Total swaps are %d \n ",count);
    return arr;
}

main()
{
    int *res; //pointer for storing returned array
    int n,i;
    printf("Enter  size of array: ");
    scanf("%d",&n);
    int arr[n];

    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    res = bubble_sort(arr,n);
    printf("Sorted array is \n");
    for(i=0;i<n;i++)
    {
        printf("%d ",res[i]);
    }
}
