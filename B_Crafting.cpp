#include<bits/stdc++.h>
#define int long long 
using namespace std;;

signed main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int a[n],b[n];
        int sum1=0,sum2=0;
        for(int i=0;i<n;i++){
            cin>>a[i];//sum1+=a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];//sum2+=b[i];
        }
        int x=0,y=0,z=1e9;
        bool ok=false;
        for(int i=0;i<n;i++){
            if(a[i]<b[i]){
                if(y!=0){
                    ok=true;break;
                }
                else y++;
                x=b[i]-a[i];
            }
        }
        if(ok)cout<<"NO";
        else{
            for(int i=0;i<n;i++){
                if(a[i]>=b[i])z=min(z,a[i]-b[i]);
            }
            cout<<((z>=x)?"YES":"NO");
        }
        cout<<endl;
    }
    return 0;
}