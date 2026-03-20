#include<bits/stdc++.h>
#define int long long 
using  namespace std;
int n,m;
const int maxN=40;
vector<int>a;

struct Node{
    int inv;
    int cnt[maxN+1];
    Node(){
        inv=0;
        memset(cnt,0,sizeof(cnt));
    }
};
Node mergeN(const Node &L,const Node &R){
    Node res;
    res.inv=L.inv+R.inv;
    int p=0;
    for(int i=1;i<=maxN;i++){
        res.inv+=1LL*L.cnt[i]*p;
        p+=R.cnt[i];
    }
    for(int i=1;i<=maxN;i++){
        res.cnt[i]=L.cnt[i]+R.cnt[i];
    }
    return res;
}
struct segTree{
  int n;
  vector<Node>t;
  segTree(int n){
    this->n=n;
    t.assign(4*n+4,Node());
    build(1,1,n);
  }
  void build(int v,int tl,int tr){
    if(tl==tr){
        t[v].cnt[a[tl]]=1;
        t[v].inv=0;
        return;
    }
    int tm=(tl+tr)>>1;
    build(v<<1,tl,tm);build(v<<1|1,tm+1,tr);
    t[v]=mergeN(t[v<<1],t[v<<1|1]);
  }  
  void update(int v,int tl,int tr,int idx,int val){
    if(tl==tr){
        t[v]=Node();
        t[v].cnt[val]=1;
        return;
    }
    int tm=(tr+tl)>>1;
    if(idx<=tm)update(v<<1,tl,tm,idx,val);
    else update(v<<1|1,tm+1,tr,idx,val);
    t[v]=mergeN(t[v<<1],t[v<<1|1]);
  }
  Node queries(int v,int l,int r,int tl,int tr){
    if(l>tr||r<tl)return Node();
    if(l<=tl && tr<=r)return t[v];
    int tm=(tl+tr)>>1;
    return mergeN(queries(v<<1,l,r,tl,tm),queries(v<<1|1,l,r,tm+1,tr));
  }
};


signed main(){
    int _=1;//cin>>_;
    while(_--){
        int n,q;cin>>n>>q;
        a.assign(n+1,0);
        for(int i=1;i<=n;i++)cin>>a[i];
        segTree st(n);
        while(q--){
            int t;cin>>t;
            if(t==1){
                int l,r;cin>>l>>r;
                cout<<st.queries(1,l,r,1,n).inv<<endl;
            }else{
                int i,v;cin>>i>>v;
                st.update(1,1,n,i,v);
            }       
        }
    }
    return 0;
}