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
        tree.assign(n*4,0);
    }
    void build(int node,int tl,int tr){
        if(tr==tl)tree[node]=a[tr];
        else{
            int tm=mid(tl,tr);
            build(node*2,tl,tm);
            build(node*2+1,tm+1,tr);
            tree[node]=min(tree[node*2],tree[node*2+1]);
        }
    }
    int query(int node,int tl,int tr,int l,int r){
        if(r<tl || l>tr)return 1e9;
        if(tr<=r && tl>=l)return tree[node];
        int tm=mid(tl,tr);
        int left=query(node*2,tl,tm,l,r);
        int right=query(node*2+1,tm+1,tr,l,r);
        return min(left,right);
    }
    void update(int node,int tl,int tr,int i,int val){
        if(tl==tr){
            tree[node]=val;return;
        }
        int tm=mid(tl,tr);
        if(i<=tm)update(node*2,tl,tm,i,val);
        else update(node*2+1,tm+1,tr,i,val);
        tree[node]=min(tree[node*2],tree[node*2+1]);
    }

};

signed main(){
    //int n,m;
    cin>>n>>m;
    a.assign(n+1,0);
    for(int i=0;i<n;i++)cin>>a[i];
    segTree st(n);
    st.build(1,0,n-1);
    while(m--){
        int t;cin>>t;
        if(t==1){
            int idx,val;cin>>idx>>val;
            st.update(1,0,n-1,idx,val);
        }else{
            int l,r;cin>>l>>r;
            cout<<st.query(1,0,n-1,l,r-1)<<endl;
        }
    }

    return 0;
}

