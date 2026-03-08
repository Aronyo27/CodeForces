#include<iostream>
#include<algorithm>

using namespace std;
int main()
{
    int n,p1,p2,array[200],count=0;
    cin>>n;
    cin>>p1;
    for (int i = 0; i <p1; i++)
    {
        cin>>array[i];
    }
    cin>>p2;
    for (int i = p1; i < p1+p2 ; i++)
    {
        cin>>array[i];
    }
    sort(array,array+(p1+p2));
    for(int i=0;i<p1+p2;i++)
    {
        if (array[i]!=array[i+1])
    {
        count++;
    }
    }
    if (count==n)
    {
        cout<<"I become the guy."<<endl;
    }
    else cout<<"Oh, my keyboard!"<<endl;
    return 0;
}