/*
GFG
Rearrange an array such that arr[i] = i
Given an array of elements of length N,
ranging from 0 to N – 1.
All elements may not be present in the array.
If element is not present then there will be -1 present in the array.
Rearrange the array such that A[i] = i and if i is not present, display -1 at that place.
*/


 #include<iostream>
 using namespace std;

 int main()
 {
     int n;
     cout<<"Size of array " ;
     cin>>n;

     int arr[n], out_arr[n] = {0};
     cout<<"Enter the array "<<endl;


     for(int i =0;i<n;i++)
     {
         cin>>arr[i];
     }

        int change;
     for(int i=0;i<n;i++)
     {
         change = 0;
         for(int j=0;j<n;j++)
         {
             if( i == arr[j])
             {
                 out_arr[i] = i;
                 change++;
             }
         }
         if(change == 0)
            out_arr[i] = -1;
     }

     cout<<"Result array is : "<<endl;

     for(int i =0;i<n;i++)
     {
         cout<<out_arr[i]<<" ";
     }
 }
