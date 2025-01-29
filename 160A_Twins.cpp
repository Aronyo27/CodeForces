#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    int n,sum=0,count=0,ans=0;
    cin>>n;
    int array[n];
    for (int i = 0; i <n; i++)
    {
        cin>>array[i];
        sum+=array[i];
    }
    sort(array,array+n, greater<int>());
    for(int i=0;i<n;i++)
    {
        ans+=array[i];
        count++;
        if((sum-ans)<ans) break;
    }
    cout<<count<<endl;
    
}