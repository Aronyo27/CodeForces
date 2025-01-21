#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b;
    cin>>a>>b; 
    int min= max(a,b);
    int d=6-min+1;
    int c= __gcd(d,6) ;
    cout<<d/c<<"/"<<6/c<<endl;
    
}