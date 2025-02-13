#include<iostream>

using namespace std;
int main()
{
    int n,police=0,crime=0;
    cin>>n;
    while(n--)
    {
        int a;
        cin>>a;
        if(a>0)
        {
            police+=a;
        }
        else
        {
            if (police<1)
            {
                crime++;
            }
            else police--; 
        }
    }
    cout<<crime;
}