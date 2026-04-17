#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
struct Node{
    int open,close,full;
    Node(int o=0,int c=0,int f=0):open(o),close(c),full(f){}
};
struct segTree{
    int n;
    vector<Node>t;
    segTree(int n){
        this->n=n;
        t.assign(4*n+5,0);
        build(1,0,n-1);
    }
    Node mergeN(Node&a,Node&b){
        int match=min(a.open,b.close);
        Node res;
        res.open=a.open+b.open-match;
        res.close=a.close+b.close-match;
        res.full=a.full+b.full+match;
        return res;
    }
    void build(int v,int tl,int tr){
        if(tl==tr){
            if(s[tl]=='(')t[v]=Node(1,0,0);
            else t[v]=Node(0,1,0);return;
        }
        int tm=(tr+tl)>>1;
        build(v<<1,tl,tm);build(v<<1|1,tm+1,tr);
        t[v]=mergeN(t[v<<1],t[v<<1|1]);        
    }
    Node query(int v,int tl,int tr,int l,int r){
        if(l>tr || r<tl)return Node(0,0,0);
        if(tl>=l&&tr<=r)return t[v];
        int tm=(tl+tr)>>1;
        Node lf=query(v<<1,tl,tm,l,r);
        Node rt=query(v<<1|1,tm+1,tr,l,r);
        return mergeN(lf,rt);
    }
};

signed main(){
    int _=1;//cin>>_;
    while(_--){
        cin>>s;
        int n=s.size();
        int m;cin>>m;
        segTree st(n);
        while(m--){
            int l,r;cin>>l>>r;
            l--,r--;
            Node ans=st.query(1,0,n-1,l,r);
            cout<<ans.full*2<<endl;
        }        
    }
    return 0;
}