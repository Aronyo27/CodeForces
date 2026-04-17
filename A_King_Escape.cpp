#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n;
int ax,ay,bx,by,cx,cy;


signed main(){
    cin>>n>>ax>>ay>>bx>>by>>cx>>cy;
    if((bx>ax && by>ay)&&(cx>ax && cy>ay))cout<<"YES"<<endl;
    else if((bx<ax && by<ay)&&(cx<ax && cy<ay))cout<<"YES"<<endl;
    else if((bx<ax && cx<ax)&&(by>ay&&cy>ay))cout<<"YES"<<endl;
    else if((bx>ax && cx>ax)&&(by<ay&&cy<ay))cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}