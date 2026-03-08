#include<bits/stdc++.h>
using namespace std;

// int main()
// {
//     long long n,k,count=0;
//     cin>>n>>k;
//     vector<long long>vec;
//     for (int i = 1; i <=n; i+=2)
//     {
//         vec.push_back(i);
//     }
//     for(int i =2 ; i<=n; i+=2)
//     {
//         vec.push_back(i);
//     }
//     cout<<vec[k-1]<<endl;

// }
int main()
{
    long long n,k,d=0,ans=0;
    cin>>n>>k;
    d=(n+1)/2;
    if(k<=d)
    {
        ans=(k*2)-1;
    }
    else
    {
        ans=(k-d)*2;
    }
    cout<<ans<<endl;

}