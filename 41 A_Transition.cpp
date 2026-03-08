#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string word , word1;
    cin>>word;
    cin>>word1;

    reverse (word1.begin(), word1.end());
    if(word1==word) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;

}   
