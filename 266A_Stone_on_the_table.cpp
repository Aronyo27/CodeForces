#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n,count=0;
    string line;
    cin>>n;
    cin>>line;
    for (int i = 0; i <n; i++)
    {
        if(line[i]==line[i+1])
        {
            count++;
        }
        
    }
    cout<<count;
    
    
    
}