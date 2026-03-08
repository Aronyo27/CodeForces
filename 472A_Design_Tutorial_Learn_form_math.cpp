#include<bits/stdc++.h>
using namespace std;
bool is_composite(int x)
{
    if(x<=1) return false;
    for (int i = 2; i*i <=x ; i++)
    {
        if (x%i==0)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int n;
    cin>>n;
    for (int i = 4; i <=n/2; i++)
    {
       int m=n-i;
       if(is_composite(i) && is_composite(m)) 
       {
        cout<<i<<" "<<m<<endl;
        return 0;
       }
    }
    
}