#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n;
    for (int i = 1; i <=5; i++)
    {
        for (int j = 1; j <=5; j++)
        {
            cin>>n;
            if (n==1)
            {
                int ans=abs(3-i)+abs(3-j);
                cout<<ans<<endl;
            }
        }
    }
    return 0;
}