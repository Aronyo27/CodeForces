#include<bits/stdc++.h>
#define int long long 
using namespace std;
vector<int>v;
int poW(int a,int k){
    int ans=1;
    while(k>0){
        if(k&1)ans*=a;
        a*=a;
        k>>=1;
    }
    return ans;
}
signed main(){
    int t;cin>>t;
    for(int i=0;;i++){
        int x=pow(3,i);
        if(x<=1e9){
            if(i==0)v.push_back(3);
            else v.push_back(poW(3,i+1)+i*pow(3,i-1));
        }
        else break;
    }
    while(t--){
        int n;cin>>n;
        int s=v.size();
        int i=s-1,ans=0;;
        while(n>0 && i>=0){
            int te=poW(3,i);
            if(te<=n){
                int cnt=n/te;
                ans+=cnt*v[i];
                n%=te;
            }    
            i--;        
        }
        cout<<ans<<endl;
    }

}