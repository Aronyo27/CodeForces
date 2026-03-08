#include<bits/stdc++.h>
using namespace std;

int main()
{
    int array[4],sum=0;
    for (int i = 0; i <4; i++)
    {
        cin>>array[i];
    }
    string n;
    cin>>n;
    for (int i = 0; i <n.size(); i++)
    {
        int position=n[i]-'1';
        sum+=array[position];
    }
    cout<<sum<<endl;
    
}
