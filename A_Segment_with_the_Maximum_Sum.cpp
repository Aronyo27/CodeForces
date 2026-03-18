#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int>a;

struct Node{
    int sum,pref,suf,ans;
};

struct segTree{
    int n;
    vector<Node>t;
    segTree(int n){
        this->n=n;
        t.assign(4*n,{0,0,0,0});
        build(1,1,n);
    }
    Node make_node(int v){
        return {v,max(0LL,v),max(0LL,v),max(0LL,v)};
    }
    Node merge(Node a,Node b){
        // Node res;
        // res.sum=a.sum+b.sum;
        return {a.sum+b.sum,max(a.pref,a.sum+b.pref),max(b.suf,b.sum+a.suf),max({a.ans,b.ans,a.suf+b.pref})};
    }
    void build(int v,int tl,int tr){
        if(tl==tr){
            t[v]=make_node(a[tl]);return;
        }
        int tm=(tl+tr)>>1;
        build(v<<1,tl,tm);
        build(v<<1|1,tm+1,tr);
        t[v]=merge(t[v<<1],t[v<<1|1]);
    }
    void update(int v,int tl,int tr,int idx,int val){
        if(tl==tr){
            t[v]=make_node(val);return;
        }
        int tm=(tl+tr)>>1;
        if(idx<=tm)update(v<<1,tl,tm,idx,val);
        else update(v<<1|1,tm+1,tr,idx,val);
        t[v]=merge(t[v<<1],t[v<<1|1]);
    }
    int answer(){
        return t[1].ans;
    }
};

signed main(){
    int _=1;//cin>>_;
    while(_--){
        int n,m;cin>>n>>m;
        a.assign(n+1,0);
        for(int i=1;i<=n;i++)cin>>a[i];
        segTree st(n);
        cout<<st.t[1].ans<<endl;
        for(int i=0;i<m;i++){
            int idx,v;cin>>idx>>v;
            st.update(1,1,n,idx+1,v);
            cout<<st.answer()<<endl;   
        }
    }
    return 0;
}

/**
 * Input :
 *  5 2
    5 -4 4 3 -5
    4 3
    3 -1
 *Output:
    8
    11
    7
 */