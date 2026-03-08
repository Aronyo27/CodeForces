#include<bits/stdc++.h>
#define int long long 
using namespace std;
signed main(){
    int t;cin>>t;
    while(t--){
        int n,q;cin>>n>>q;
        vector<int>a(n),b(n);
        for(int &i:a)cin>>i;
        for(int &i:b)cin>>i;
        vector<int>mx(n);
        mx[n-1]=max(a[n-1],b[n-1]);
        for(int i=n-2;i>=0;i--){
            mx[i]=max({a[i],b[i],mx[i+1]});
        }
        vector<int>pf(n);
        pf[0]=mx[0];
        for(int i=1;i<n;i++)pf[i]=pf[i-1]+mx[i];
        for(int i=1;i<=q;i++){
            int l,r;cin>>l>>r;l--,r--;
            int ans=pf[r]-(l>0?pf[l-1]:0);
            
            cout<<ans<<" ";
        }
        cout<<endl;      

    }
}