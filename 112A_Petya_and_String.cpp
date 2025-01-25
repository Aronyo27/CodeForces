#include<iostream>
#include<string>
using namespace std;
int main()
{
   string str1,str2;
   cin>>str1>>str2;
   for(int i=0; i<str1.size(); i++)
   {
    str1[i]=towlower(str1[i]);
    str2[i]=towlower(str2[i]);
    if (str1[i]>str2[i])
    {
        cout<<"1"<<endl;
        break;
    }
    if(str1[i]<str2[i])
    {
        cout<<"-1"<<endl;
        break;
    }
   }
    if(str1==str2)
   {
    cout<<"0"<<endl;
   }
   
   return 0;
}