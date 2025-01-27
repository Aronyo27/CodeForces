#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int k,l,m,n,d,count=0;
    cin>>k>>l>>m>>n>>d;
    for (int i = 1; i <=d; i++)
    {
        if (i%m==0 || i%n==0 || i%k==0 || i%l==0 )
        {
            count++;
        }
        
    }
    cout<<count<<endl;
    
}