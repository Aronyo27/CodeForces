#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,x,y,n,m,v;

int32_t main(){
    int _=1;//cin>>_;
    while(_--){
        cin>>n>>m;
        vector<int>a(n),b(n);
        int t=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            t+=a[i];
            b[i]=t;
        }
        for(int i=0;i<m;i++){
            cin>>v;
            int idx=lower_bound(b.begin(),b.end(),v)-b.begin();
            int prev=(idx==0)?0:b[idx-1];
            int z=v-prev;
            cout<<idx+1<<" "<<z<<endl;          
        }
    }
    return 0;
}