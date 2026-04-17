#include<bits/stdc++.h>
#define int long long 
using namespace std;
int _,n,k;
vector<int>a,b,c;

signed main(){
    cin>>_;
    while(_--){
        cin>>n>>k;
        a.assign(n,0),b.assign(n,0);
        for(int &i:a)cin>>i;
        for(int &i:b)cin>>i;
        bool ok=true;
        for(int i=0;i<n;i++){
            if(i<n-k || i>=k){
            if(b[i]==-1)b[i]=a[i];
            if(b[i]!=a[i])ok=false;
        }
        }      
        set<int>s;
        for(int &val:b){
            if(val>=0){
                if(s.count(val))ok=false;
                s.insert(val);
            }
        }      
        cout<<(ok?"YES":"NO")<<endl;
        done : ;
    }
    return 0;
}