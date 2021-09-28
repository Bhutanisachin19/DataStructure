/*
GFG
Find maximum value of Sum( i*arr[i]) with only rotations on given array allowed
*/


#include<iostream>
using namespace std;
int main()
{
    int arr[] =  {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int len = sizeof(arr)/ sizeof(arr[0]);

    int max_num = arr[0];
    int max_index=0;

    for(int i=0;i<len;i++)
    {
        if(arr[i] > max_num)
        {
            max_num = arr[i];
            max_index = i;
        }
    }

    //no of rotation of index + 1
    //Rotation
    int rotation_num = max_index +1;
    int temp[rotation_num];

    for(int i=0;i<rotation_num;i++)
    {
        temp[i] = arr[i];
    }

    int num = 0;
    for(int i=0;i<len;i++)
    {
        arr[i] = arr[i + rotation_num];

        if(i >= len-rotation_num)
        {
            arr[i] = temp[num];
            num++;
        }
    }

    int number = 0;
    for(int i=0;i<len;i++)
    {
        number += i * arr[i];
    }

    cout<<"Max number is "<<number;


}
