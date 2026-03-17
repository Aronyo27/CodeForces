#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
vector<int>a;
int mid(int l,int r){return (r-l)/2+l;}
struct segTree{
    int n;
    vector<int>t;
    segTree(int n){
        this->n=n;
        t.assign(4*n,0);
    }
    void build(int node,int tl,int tr){
        if(tl==tr)t[node]=a[tl];
        else{
            int tm=mid(tl,tr);
            build(node*2,tl,tm);
            build(node*2+1,tm+1,tr);
            t[node]=t[node*2]+t[node*2+1];
        }
    }
    int qm(int node,int tl,int tr,int l,int r){
        if(r<tl || l>tr)return 0;
        if(l<=tl && r>=tr)return t[node];
        int tm=mid(tl,tr);
        int lf=qm(node*2,tl,tm,l,r);
        int rt=qm(node*2+1,tm+1,tr,l,r);
        return lf+rt;
    }
    void update(int node,int tl,int tr,int i,int val){
        if(tl==tr){
            t[node]+=val;return;
        }
        int tm=mid(tl,tr);
        if(i<=tm)update(node*2,tl,tm,i,val);
        else update(node*2+1,tm+1,tr,i,val);
        t[node]=(t[node*2]+t[node*2+1]);
    }
};
void cm(){
    vector<int>comp=a;
    sort(comp.begin(),comp.end());
    comp.erase(unique(comp.begin(),comp.end()),comp.end());
    for(int i=0;i<n;i++){
        a[i]=lower_bound(comp.begin(),comp.end(),a[i])-comp.begin()+1;
    }
}

signed main(){
    int t=1;//cin>>t;
    while(t--){
        cin>>n;
        a.assign(n,0);
        for(int i=0;i<n;i++)cin>>a[i];
        cm();
        vector<int>lt(n),rt(n);
        int m=0;
        for(int y:a)m=max(m,y);
        segTree st(m);
        for(int i=0;i<n;i++){
            lt[i]=i-st.qm(1,1,m,1,a[i]);
            st.update(1,1,m,a[i],1);
        }
        segTree st1(m);
        for(int i=n-1;i>=0;i--){
            rt[i]=st1.qm(1,1,m,1,a[i]-1);
            st1.update(1,1,m,a[i],1);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=lt[i]*rt[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}