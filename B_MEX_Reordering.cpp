#include<bits/stdc++.h>
//#define int long long 
using namespace std;;

signed main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        unordered_map<int,int>m;
        for(int i=0;i<n;i++)m[a[i]]++;
        if(m[0]==0)cout<<"NO";
        else if(m[1]>=1)cout<<"YES";
        else if(m[0]!=1){cout<<"NO";}
        else cout<<"YES";
        cout<<endl;

    }
}