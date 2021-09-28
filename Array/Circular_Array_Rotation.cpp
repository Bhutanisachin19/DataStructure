
#include<iostream>
using namespace std;


class A{
    int siz,no_of_rotations,qur;
public:
    void code()
    {
        cout<<"Enter the size of array ";
        cin>>siz;
        cout<<"Enter the no of rotations ";
        cin>>no_of_rotations;
        cout<<"Enter queries ";
        cin>>qur;

        int arr[siz];

        cout<<"Enter elements of the array ";
        for(int i=0;i<siz;i++)
        {
            cin>>arr[i];
        }


        while(no_of_rotations!=0)
        {
            int end=arr[siz-1];
            for(int i=siz-2;i>=0;i--)
            {
                arr[i+1]=arr[i];
            }
            arr[0]=end;
            no_of_rotations--;
        }


        for(int i=0;i<siz;i++)
        {
            cout<<arr[i]<<" ";
        }
    }
};
main()
{
    A obj;
    obj.code();
}
