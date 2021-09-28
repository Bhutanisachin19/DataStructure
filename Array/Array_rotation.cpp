//GFG

/*
Rotate an array of size n by d  elements

Complexity of the code is:
Time complexity : O(n)
Auxiliary Space : O(d)
*/




#include<iostream>
using namespace std;

void rotate_array(int arr[], int d, int n)
{
    int temp[d];

    for(int i=0;i<d;i++)
    {
        temp[i] = arr[i];
    }

    int num = 0;
    for(int i=0;i<n;i++)
    {
         if(i >= n-d)
        {
            arr[i] = temp[num];
            num++;
        }
        else
            arr[i] = arr[i + d];
    }


    cout<<"rotated array is "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int n, d;
    cout<<"Enter size of array "<<endl;
    cin>>n;

    cout<<"Enter no of rotations " <<endl;
    cin>>d;

    int arr[n];
    cout<<"Enter array "<<endl;

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    rotate_array(arr, d , n);
}
