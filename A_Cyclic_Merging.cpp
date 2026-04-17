#include<bits/stdc++.h>
#define int long long
using namespace std;


signed main(){
    int _;cin>>_;
    while(_--){
        int n;cin>>n;
        vector<int>a(n);;
        int maxVal=-1e9;
        for(int i=0;i<n;i++){
            cin>>a[i];
            maxVal=max(maxVal,a[i]);
        }
        int total=0;
        for(int i=0;i<n;i++){
            int t=(i+1)%n;
            total+=max(a[i],a[t]);
        }
        cout<<total-maxVal<<endl;     
    }
    return 0;
}