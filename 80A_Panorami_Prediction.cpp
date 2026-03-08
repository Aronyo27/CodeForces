#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,ans;
    cin>>a>>b;
    for (int i = a+1; ; i++)
    {
        int count=0;
        for (int j = 2; j < i; j++)
        {
            if(i%j==0) 
            {
                count++;
            }
        } 
        if(count==0)
        {
            ans=i;
            break;
        }
    }
    if(ans==b)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}