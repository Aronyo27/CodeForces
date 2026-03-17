#include<bits/stdc++.h>
#define int long long
using namespace std;
int mid(int l,int r){return (r-l)/2+l;}

struct segTree{
    int n;
    vector<int>tree;
    segTree(int n){
        this->n=n;
        tree.assign(n*4,0);       
    }
    void update(int node,int tl,int tr,int idx,int val){
        if(tl==tr){
            tree[node]+=val;
            return;
        }
        int tm=(tr+tl)>>1;
        if(idx<=tm)update(node*2,tl,tm,idx,val);
        else update(node*2+1,tm+1,tr,idx,val); 
        tree[node]=tree[node<<1]+tree[(node<<1)+1];
    }
    int query(int node,int tl,int tr,int l,int r){
        if(r<tl || l>tr)return 0;
        if(l<=tl && tr<=r)return tree[node];
        int tm=mid(tl,tr);
        int lf=query(node*2,tl,tm,l,r);
        int rt=query(node*2+1,tm+1,tr,l,r);
        return lf+rt;
    }
};


signed main(){
    int t=1;//cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>a(n+1),lf(n+1),rt(n+1);
        for(int i=1;i<=n;i++)cin>>a[i];
        unordered_map<int,int>cnt;
        for(int i=1;i<=n;i++){
            cnt[a[i]]++;
            lf[i]=cnt[a[i]];
        }
        cnt.clear();
        for(int i=n;i>=0;i--){
            cnt[a[i]]++;
            rt[i]=cnt[a[i]];
        }
        segTree st(n);
        int ans=0;
        for(int i=n;i>=1;i--){
            ans+=st.query(1,1,n,1,lf[i]-1);
            st.update(1,1,n,rt[i],1);
        }
        cout<<ans<<endl;
    }
    return 0;
}