#include<bits/stdc++.h>
#define int long long 
using namespace std;
void fast_io(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

struct segTree{
    int n;
    vector<int>t;
    segTree(int n):n(n){
        t.assign(4*n+4,-1);
    }
    void update(int v,int l,int r,int idx,int val){
        if(l==r){
            t[v]=val;return;
        }
        int m=(l+r)>>1;
        if(idx<=m)update(v<<1,l,m,idx,val);
        else update(v<<1|1,m+1,r,idx,val);
        t[v]=max(t[v>>1],t[v>>1|1]);
    }
    int find(int v,int tl,int tr,int l,int r,int y){
        if(r<tl || l>tr || t[v]<=y)return -1;
        if(l==r)return 1;
        int tm=(tl+tr)>>1;
        int left=find(v<<1,tl,tm,l,r,y);
        if()


    }


};





signed main(){
    fast_io();
    int _=1;//cin>>_;
    while(_--){
        int n;cin>>n;
        while(n--){
            string type;cin>>type;
            if(type=="add"){

            }else if(type=="find"){

            }else{

            }
        }
    }
    return 0;
}