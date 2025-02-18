#include<iostream>

using namespace std;
int main()
{
    long long int n;
    cin>>n;
    
        if (n%2==0)
        {
            cout<<n/2<<endl;
        }
        else 
        {
            long long int sum=-(n/2+1);
            cout<<sum<<endl;
        }
    return 0;
}