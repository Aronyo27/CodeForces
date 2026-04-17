#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m,k;

int sol(int s){
    int lf=k-1,rt=n-k;
    int low=max(0LL,s-rt);
    int high=min(lf,s);

    if(low>high)return 0;
    //int s1=s/2 , s2=(s+1)/2;
    for(int i=low;i<=high;i++){
        int y=s-i;
        int nd=2*max(i,y)+min(i,y)-1;
        if(nd<=m)return 1;
    }
    return 0;
}
signed main(){
    int t;cin>>t;
    while(t--){
        cin>>n>>m>>k;
        int l=0,r=n-1,ans=0;
        while(l<=r){
            int mm=(l+r)>>1;
            if(sol(mm))ans=mm,l=mm+1;
            else r=mm-1;
        }
        cout<<ans+1<<endl;
    }
}