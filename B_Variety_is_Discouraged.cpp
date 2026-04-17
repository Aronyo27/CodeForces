#include<bits/stdc++.h>
#define int long long 
using namespace std;


signed main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>a(n),dist(n+1,0);
        for(int &i:a){
            cin>>i;dist[i]++;
        }
        int ans=0,idxL=-1,idxR=-1;
        int i=0;
        while(i<n){
            if(dist[a[i]]!=1){
                i++;continue;
            }
            int j=i;
            while(j<n&&dist[a[j]]==1)j++;
            int len=j-i;
            if(len>ans){
                ans=len;
                idxL=i+1,idxR=j;
            }
            i=j;
        }
        if(ans==0)cout<<ans;
        else cout<<idxL<<" "<<idxR;
        cout<<endl;

    }
    return 0;
}