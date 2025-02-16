#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,count2=0;
        cin>>n>>k;
        int line=n/k;
        int count1=line;
        for (int i = 1; i <=n; i++)
        {
         
            if(i%k==0) 
            {
                count2++;
                cout<<count2<<" ";
            }
            else
            {count1++; cout<<count1<<" "; }
        }
        cout<<endl;
        

        
    }
    return 0;
}
