#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>programming ,mathematics ,pe;
    for (int i = 0; i <n; i++)
    {
        int a;
        cin>>a;
        if (a==1)
        {
            programming .push_back(i+1);
        }
        if (a==2)mathematics.push_back(i+1);
        if(a==3)pe.push_back(i+1);
        
    }
    int min=(programming.size(),mathematics.size(),pe.size());
    cout<<min<<endl;
    for (int i=0;i<min;i++)
    {
        cout<<programming[i]<<" "<<mathematics[i]<<" "<<pe[i]<<endl;
    }
    return 0;
    
}
