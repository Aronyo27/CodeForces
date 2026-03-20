#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m;
const int N=1<<17;
int a[N],t[4*N+4];
struct segTree{
    int n;
    segTree(int a[],int sz){
        n=sz;
        build(1,1,1<<n,(n%2)!=0);
    }
    void build(int v,int tl,int tr,int isor){
        if(tl==tr){
            t[v]=a[tl];return;
        }
        int tm=(tl+tr)>>1;
        build(v<<1,tl,tm,!isor);build(v<<1|1,tm+1,tr,!isor);
        if(isor){
            t[v]=t[v<<1]|t[v<<1|1];
        }else{
            t[v]=t[v<<1]^t[v<<1|1];
        }
    }
    void update(int v,int tl,int tr,int idx,int val,int isor){
        if(tl==tr){
            t[v]=val;return;
        }
        int tm=(tl+tr)>>1;
        if(idx<=tm)update(v<<1,tl,tm,idx,val,!isor);
        else update(v<<1|1,tm+1,tr,idx,val,!isor);
        if(isor){
            t[v]=t[v<<1]|t[v<<1|1];
        }else{
            t[v]=t[v<<1]^t[v<<1|1];
        }
    }

};

signed main(){
    int _=1;//cin>>_;
    while(_--){
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=(1<<n);i++)cin>>a[i];
        segTree st(a,n);
        while(m--){
            int p,b;cin>>p>>b;
            st.update(1,1,1<<n,p,b,(n%2!=0));
            cout<<t[1]<<endl;
        }
    }
    return 0;
}