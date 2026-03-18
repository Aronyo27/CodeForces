#include<bits/stdc++.h>
#define int long long 
using  namespace std;
int n,m;
vector<int>a;

struct segTree{
    int n;
    vector<int>t;
    segTree(int n){
        this->n=n;
        t.assign(4*n,0);
        build(1,1,n);
    }
    void build(int v,int tl,int tr){
        if(tl==tr){
            t[v]=a[tl];return;
        }
        int tm=(tl+tr)>>1;
        build(v<<1,tl,tm);
        build(v<<1|1,tm+1,tr);
        t[v]=t[v<<1]+t[v<<1|1];
    }    
    void update(int v,int tl,int tr,int idx){
        if(tl==tr){
            a[idx]^=1;
            t[v]=a[idx];return;
        }
        int tm=(tl+tr)>>1;
        if(idx<=tm)update(v<<1,tl,tm,idx);
        else update(v<<1|1,tm+1,tr,idx);
        t[v]=t[v<<1]+t[v<<1|1];
    }
    int kth(int v,int tl,int tr,int k){
        if(tr==tl)return tl;
        int os=t[v<<1];
        int tm=(tl+tr)>>1;
        if(k<os)return kth(v<<1,tl,tm,k);
        else return kth(v<<1|1,tm+1,tr,k-os);
    }
};

signed main(){
    int _=1;//cin>>_;
    while(_--){
        cin>>n>>m;//array size,queries
        a.assign(n+1,0);
        for(int i=1;i<=n;i++)cin>>a[i];
        segTree st(n);
        for(int i=0;i<m;i++){
            int tp,x;cin>>tp>>x;
            if(tp==1){
                  st.update(1,1,n,x+1);
            }else{
                cout<<st.kth(1,1,n,x)-1<<endl;
            }
        }
    }
    return 0;
}