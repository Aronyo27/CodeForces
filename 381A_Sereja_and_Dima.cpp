#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++) cin>>array[i];
    int sereja=0 ,dima=0 ;
    int l=0,r=n-1;
    int z=0;
    while(l<=r)
    {
        if(z%2==0)
        {
            if(array[l]>array[r])
            {
                sereja+=array[l];
                l++;
            }
            else 
            {
            sereja+=array[r];
            r--;
            }
        }
        else 
        {
            if(array[l]>array[r])
            {
                dima+=array[l];
                l++;
            }
            else
            { 
            dima+=array[r];
            r--;
            }
        }
        z++;
    }
    cout<<sereja<<" "<<dima<<endl;
}