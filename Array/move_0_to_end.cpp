

#include<iostream>
using namespace std;

int main()
{
    int arr[] ={0,0,1,0,5,0,3,9,10,0,0,11};
    int n = sizeof(arr)/sizeof(arr[0]);


    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]==0 && arr[j]>0)
            {
                //swap
                int temp;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }

        }
    }


    for(int i=0;i<n;i++)
    {
        cout<<arr[i] <<" ";
    }
}
