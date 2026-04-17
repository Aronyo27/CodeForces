#include<bits/stdc++.h>
using namespace std;
int a,b,c,x,y,z;

int32_t main(){
    int _;cin>>_;
    while(_--){
        int n;cin>>n;
        vector<int>ans;
        int f=(1<<n)-1;
        ans.push_back(f);
        for(int i=n-1;i>=0;i--){
            a=(1<<i)-1;
            b=1<<(i+1);
            c=1<<(n-1-i);
            for(int k=0;k<c;k++){
                x=a+k*b;
                ans.push_back(x);
            }
        }
        for(int &i:ans)cout<<i<<" ";
        cout<<endl;        
    }
    return 0;
}