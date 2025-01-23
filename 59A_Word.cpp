#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int up=0,low=0;
    string word ;
    cin>>word;

    for (int  i = 0; i <word.size(); i++)
    {
        if (isupper(word[i]))
        {
            up++;
        }
        else
            low++;
    }
    if (up<low || up==low)
    {
        for (int  i = 0; i <word.size(); i++)
    {
        word[i]=tolower(word[i]);
    }
    cout<<word<<endl;
    }
    if (up>low)
    {
        for (int  i = 0; i <word.size(); i++)
    {
        word[i]=toupper(word[i]);
    }
    cout<<word<<endl;
    }
    return 0;
}