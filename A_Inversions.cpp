#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m;
vector<int>a;
int mid(int l,int r){return (r-l)/2+l;}


struct segTree{
    int n;
    vector<int>tree;
    segTree(int n){
        this->n=n;
        tree.assign(4*n,0);
    }
    void build(int node,int tl,int tr){
        if(tl==tr)tree[node]=a[tl];
        else{
            int tm=mid(tl,tr);
            build(node*2,tl,tm);
            build(2*node+1,tm+1,tr);
            tree[node]=tree[node*2]+tree[node*2+1];
        }
    }
    int query(int node,int tl,int tr,int l,int r){
        if(r<tl || l>tr)return 0;
        if(tl>=l && tr<=r)return tree[node];
        int tm=mid(tl,tr);
        int left=query(node*2,tl,tm,l,r);
        int right=query(node*2+1,tm+1,tr,l,r);
        return left+right;
    }
    void update(int node,int tl,int tr,int i,int val){
        if(tl==tr){
            tree[node]=val;return;
        }
        int tm=mid(tl,tr);
        if(i<=tm)update(node*2,tl,tm,i,val);
        else update(node*2+1,tm+1,tr,i,val);
        tree[node]=(tree[node*2]+tree[node*2+1]);
    }   
};

signed main(){
    cin>>n;
    a.assign(n+1,0);
    for(int i=1;i<=n;i++)cin>>a[i];
    segTree st(n);
    //st.build(1,1,n-1);
    for(int i=1;i<=n;i++){
        int ans=0;
        if(a[i]<=n-1)ans=st.query(1,1,n,a[i]+1,n);
        cout<<ans<<" ";
        st.update(1,1,n,a[i],1);
    }
    return 0;
}
