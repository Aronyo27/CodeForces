#include<bits/stdc++.h>
#define int long long 
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int x,y;cin>>x>>y;
        if(x>y){
            cout<<"NO"<<endl;continue;
        }
        int n=x+y;
        if(n%2==0&&x==0){
            cout<<"NO"<<endl;continue;
        }
        if(n%2==1&&y==0){
            cout<<"NO"<<endl;continue;
        }
        vector<pair<int,int>>ans;
        if(n%2==0){
            vector<int>seq;
            
        }
    }


}