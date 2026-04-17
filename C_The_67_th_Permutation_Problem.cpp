#include<bits/stdc++.h>
#define int long long 
using namespace std;


signed main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        //vector<int>a(n);
        for(int i=1;i<=n;i++){
            cout<<i<<" "<<n+2*i-1<<" "<<2*i+n<<" ";
        }
        cout<<endl;
 
    }
}