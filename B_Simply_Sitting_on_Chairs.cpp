#include<bits/stdc++.h>
#define int long long 
using namespace std;
vector<int>a,dp;;

signed main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        a.assign(n+1,0),dp.assign(n+1,0);
        vector<int>pos(n+1);
        int cnt=0,ans;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            pos[a[i]]=i;
            if(a[i]<=i)cnt++;
            ans=cnt;
        }
        //for(int i=1;i<=n;i++)cout<<pos[i]<<" ";
        int c=0;
        for(int i=1;i<=n;i++){
            if(pos[i]<i){
                ans=max(ans,i-1-c);
                c++;
            }
        }
        cout<<ans<<endl;

    }
}