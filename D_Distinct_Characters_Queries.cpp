#include<bits/stdc++.h>
#define int long long 
using namespace std;
string s;
int q;
struct segTree{
    int n;
    vector<int>t;
    segTree(int n){
        this->n=n;
        t.resize(4*n,0);
        build(1,1,n);
    }
    int getMask(char c){
        return 1LL<<(c-'a');
    }
    void build(int v,int tl,int tr){
        if(tl==tr){
            t[v]=getMask(s[tl-1]);
            return ;
        }
        int tm=(tl+tr)>>1;
        build(v<<1,tl,tm);
        build(v<<1|1,tm+1,tr); 
        t[v]=t[v<<1]|t[v<<1|1];
    }
    void update(int v,int tl,int tr,char c,int i){
        if(tl==tr){
            t[v]=getMask(c);
            s[i-1]=c;
            return;
        }
        int tm=(tl+tr)>>1;
        if(i<=tm)update(v<<1,tl,tm,c,i);
        else update(v<<1|1,tm+1,tr,c,i);
        t[v]=t[v<<1]|t[v<<1|1]; 
    }
    int query(int v,int tl,int tr,int l,int r){
        if(tr<l || r<tl)return 0;
        if(l<=tl && tr<=r)return t[v];
        int tm=(tl+tr)>>1;
        return query(v<<1,tl,tm,l,r)|query(v<<1|1,tm+1,tr,l,r);
    }
};


signed main(){
    int _=1;//cin>>_;
    while(_--){
        cin>>s;
        cin>>q;
        int n=s.size();
        segTree st(n);
        for(int i=0;i<q;i++){
            int type;cin>>type;
            if(type==1){
                int pos;cin>>pos;
                char c;cin>>c;
                st.update(1,1,n,c,pos);
            }else{
                int l,r;cin>>l>>r;
                cout<<__builtin_popcountll(st.query(1,1,n,l,r))<<endl;
            }
        } 
    }
    return 0;
}