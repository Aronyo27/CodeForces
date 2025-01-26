#include<iostream>
using namespace std;
int main()
{
    int n,i;
    cin>>n;
    int friends[n];
    int to_gift[n];
    for (int i = 1; i <=n; i++)
    {
        cin>>friends[i];
        to_gift[friends[i]]=i;
    }
    for (int i = 1; i <= n; i++)
    {
        cout<<to_gift[i]<<" ";
    }
    return 0;
    
    
}