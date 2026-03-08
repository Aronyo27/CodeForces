#include<bits/stdc++.h>
#define int long long 
using namespace std;

signed main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>a(n+1,-1);
        vector<vector<int>>pos(n+1);
        for(int i=1;i<=n;i++){
            int x;cin>>x;
            if(x<n){
                a[i]=x;
                pos[x].push_back(i);
            }      
        }
        int cnt=0;
        for(int i=1;i*i<=n;i++){
            for(int j=i;j*i<=n;j++){
                int tar=i*j;
                if(i!=j){
                    for(int &it:pos[i]){
                        int tj=tar+it;
                        if(tj<=n && a[tj]==j)cnt++;
                    }
                    for(int &it:pos[j]){
                        int tj=tar+it;
                        if(tj<=n && a[tj]==i)cnt++;
                    }
                }
                else {
                    for(int &it:pos[i]){
                        int tj=tar+it;
                        if(tj<=n && a[tj]==j)cnt++;
                    }
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}