#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,k;
int temp=-1;

void rec(int n,int counter){
    if(n<k || n==0)return;
    int a=(n+2-1)/2;
    int b=n/2;
    if(n==k){temp=counter;return;}
    counter++;
    rec(a,counter);
    if(a!=b)rec(b,counter);
}
signed main(){
    int t;cin>>t;
    while(t--){
        cin>>n>>k;
        // queue<pair<int,int>>q;
        // q.push({n,0});
        // while(!q.empty()){
        //     auto [a,b]=q.front();q.pop();
        //     if(a==k){
        //         temp=b;break;
        //     }
        //     if(a<k || a==0)continue;
        //     int c=(a+1)/2,d=a/2;
        //     q.push({c,b+1});
        //     if(c!=d)q.push({d,b+1});
        // }
        
        int l=n,r=n;
        int cnt=0;
        while(!(l<=k&&k<=r)){
            if(k>r)break;
            l=l/2;
            r=(r+1)/2;
            cnt++;
        }
        if(l<=k&&k<=r)cout<<cnt<<endl;
        else cout<<"-1"<<endl;        
    }
    return 0;
}
