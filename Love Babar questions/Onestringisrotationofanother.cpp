//check whether one string is rotation of another



#include<iostream>
#include<string>
using namespace std;

int main()
{
    cout<<"Enter 1st string"<<endl;
    string s1;
    getline(cin,s1);

    cout<<"Enter 2nd string"<<endl;
    string s2;
    getline(cin,s2);

    cout<<"Strings you entered are "<<endl;
    cout<<s1<<endl;
    cout<<s2<<endl;

    if(s1.length() == s2.length())
    {
        string temp = s1 + s1;
        cout<<"Temp string is "<<temp<<endl;

        int occurance = temp.find(s2);

        //npos is mainly used to represent match not found

        if(occurance != string::npos)
            cout<<"Strings are rotations of each other "<<endl;
        else
            cout<<"Strings are not rotations of each other"<<endl;

    }
}
