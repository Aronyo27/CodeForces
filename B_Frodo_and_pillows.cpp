#include<bits/stdc++.h>
#define int long long 
using namespace std;

int sum(int x,int len){
    if(len<=x-1){
        int last=x-len;
        return (last+x-1)*(len)/2;
    }else{
        int s1=(x-1)*x/2;
        int s2=len-(x-1);
        return s1+s2;
    }
}
bool ok(int x,int n,int m,int k){
    int left=sum(x,k-1);
    int right=sum(x,n-k);

    int total=left+right+x;
    return total<=m;
}

signed main(){
    int t=1;//cin>>t;
    while(t--){
        int n,m,k;cin>>n>>m>>k;
        int l=1,r=m,ans=0;
        while(l<=r){
            int mi=(r-l)/2+l;
            if(ok(mi,n,m,k)){
                ans=mi;l=mi+1;
            }else{
                r=mi-1;
            }
        }
        cout<<ans<<endl;
    }
}
