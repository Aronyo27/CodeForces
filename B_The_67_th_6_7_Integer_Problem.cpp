#include<bits/stdc++.h>
#define int long long 
using namespace std;


signed main(){
    int t;cin>>t;
    while(t--){
        //int n;cin>>n;
        vector<int>a(7);
        int sum=0,maX=-1e9;
        for(int &i:a){
            cin>>i;
            sum-=i;
            maX=max(i,maX);
        }
        cout<<sum+2*maX<<endl;
    }
}