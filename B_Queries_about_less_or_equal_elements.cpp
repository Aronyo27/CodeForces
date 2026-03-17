#include<bits/stdc++.h>
//#define int long long
using namespace std;


signed main(){
    int t=1;//cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        vector<int>a(n),b(m);
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<m;i++)cin>>b[i];
        vector<int>c=a;
        sort(c.begin(),c.end());
        for(int i=0;i<m;i++){
            int ans=upper_bound(c.begin(),c.end(),b[i])-c.begin();
            cout<<ans<<" ";         
        }
        cout<<endl;
    }
    return 0;
}