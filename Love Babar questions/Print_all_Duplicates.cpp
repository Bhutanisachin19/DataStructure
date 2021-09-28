
#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    getline(cin,s);

    cout<<"String you entered is "<<endl;
    cout<<s<<endl;

    int alphabets[25] = {0} , n;

    for(int i=0;i<s.length();i++)
    {
        n = s[i];
        n = n - 97;
        alphabets[n]++;
    }

    string temp;
    int asc;
    for(int i=0;i<=25;i++)
    {

        asc =0;
        if(alphabets[i] > 1)
        {
            asc = i + 97;
            temp = asc;

            cout<<temp<<" = "<<alphabets[i]<<endl;
        }

        //cout<<alphabets[i]<<endl;
    }
}
