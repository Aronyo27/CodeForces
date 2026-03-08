#include<iostream>
#include<string>
#include<bits/stdc++.h>

using namespace std;
int main()
{
    string s;
    int count=0;
    getline(cin,s);
    sort(s.begin(),s.end());
    for (int i = 0; i < s.size()-1; i++)
    {
        if (s[i]=='{' || s[i]==','|| s[i]==' '||s[i]=='}')
        {
            continue;
        }
        else{ if (s[i]!=s[i+1])
        {
            count++;
        }}
        
        
    }
    cout<<count<<endl;
    return 0;
    

}