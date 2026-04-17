#include<bits/stdc++.h>
using namespace std;

signed main(){
    int t;cin>>t;
    while(t--){
        int x,y;cin>>x>>y;
        if(y>0)x-=y*2;
        else if(y<0)x-=-y*4;
        if(x%3==0 && x>=0)puts("YES");
        else puts("NO");               
    }
}