#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,h;
vector<int>a;

bool check(int idx){
    vector<int>t;
    for(int i=0;i<idx;i++)t.push_back(a[i]);
    sort(t.begin(),t.end());
    int b=0;
    for(int i=t.size()-1;i>=0;i-=2){
        b+=t[i];
    }
    return b<=h;
}

signed main(){
    cin>>n>>h;
    //vector<int>a(n);
    a.assign(n,0);
    for(int i=0;i<n;i++)cin>>a[i];
    int l=0,r=n,ans=0;
    while(l<=r){
        int m=(l+r)>>1;
        if(check(m)){
            ans=m;l=m+1;
        }else r=m-1;
    }    
    cout<<ans<<endl;
    return 0;
}