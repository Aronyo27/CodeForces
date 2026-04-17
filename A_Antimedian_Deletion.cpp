#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
vector<int>a;

signed main(){
    int _;cin>>_;
    while(_--){
    cin>>n;
    a.assign(n,0);
    for(int &i:a)cin>>i;
    if(n==1)cout<<"1"<<endl;
    else{
        for(int i:a)cout<<2<<" ";
        cout<<endl;
    }
}
}