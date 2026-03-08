#include<iostream>
#include<string>
using namespace std;

int main()
{
    int count1=0,count2=0;
    string line;
    cin>>line;
    for (int  i = 0; i <line.size(); i++)
    {
        if (line[i]=='7' || line[i]=='4')
        {
             count1++;  
        }
        else
            count2++;
    }
    if (count1==7 || count1==4)
    {
        cout<<"YES"<<endl;
    }
    else
        cout<<"NO"<<endl;
    return 0;
    
}