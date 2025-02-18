#include<bits/stdc++.h>
using namespace std;
using i_= int;
int main()
{
        // i_ n,i,sum1=0,sum2=0;
        // cin>>n;
        // for ( i = 1; ; i++)
        // {
        //     sum2+=i;
        //     sum1+=sum2;
        //     if( (sum1+sum2+1)>n ) break;
        // }
        // cout<<i<<endl;
        i_ n,sum=0,count=0;
        cin>>n;
        while(sum<=n)
        {
            count++;
            sum+=((count*(count+1))/2);
        }
        cout<<count-1<<endl;

    
}