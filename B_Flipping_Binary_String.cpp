#include<bits/stdc++.h>
#define int long long 
using namespace std;
signed main(){
    int _;cin>>_;
    while(_--){
        int n;cin>>n;
        string s;cin>>s;
        int ones=0;
        for(int i=0;i<n;i++)if(s[i]=='1')ones++;
        //cout<<ones<<endl;return 0;
        int zeros=n-ones;
        //cout<<zeros<<endl;return 0;
        if(ones%2==0){
            cout<<ones<<endl;
            for(int i=0;i<n;i++)if(s[i]=='1')cout<<i+1<<" ";
            cout<<endl;
        }
        else if(zeros%2!=0){
            cout<<zeros<<endl;
            for(int i=0;i<n;i++)if(s[i]=='0')cout<<i+1<<" ";
            cout<<endl;
        }
        else cout<<-1<<endl;
        //return 0;
    }
    return 0;
}