
#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the size of array "<<endl;
    cin>>n;

    int arr[n];

    cout<<"Enter the array "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int rev[n];

    for(int i=0 , j = n-1;i<n; i++, j-- )
    {
       rev[j] = arr[i];
    }


    cout<<"Array is "<<endl;

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

     cout<<endl<<"Reverse Array is "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<rev[i]<<" ";
    }

}
