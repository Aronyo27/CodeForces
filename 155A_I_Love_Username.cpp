#include<iostream>

using namespace std;

int main()
{
    int n,count=0,max,min;
    cin>>n;
    int performane[n];
    for (int i = 0; i < n; i++)
    {
        
        cin>>performane[i];
        if (i==0)
        {
            max=performane[i];
            min=performane[i];
        }
        
        if (performane[i]>max)
        {
            max=performane[i];
            count++;
        }
        if (min>performane[i])
        {
            min=performane[i];
            count++;
        }
        
    }
    cout<<(count)<<endl;
    
}