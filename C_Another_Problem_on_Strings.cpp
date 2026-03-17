#include <bits/stdc++.h>
#define int long long
using namespace std;


signed main(){
    int t=1;
    while(t--){
        int n;string s;
        cin>>n>>s;
        vector<int>cnt(s.size()+1,0);
        cnt[0]=1;
        int ans=0,sum=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1')sum++;
            if(sum>=n)ans+=cnt[sum-n];
            cnt[sum]++;
        }
        cout<<ans<<endl;
    }
    return 0;
}