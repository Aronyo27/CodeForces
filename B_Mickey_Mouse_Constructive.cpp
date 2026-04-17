#include<bits/stdc++.h>
#define int long long
using namespace std;
int _,x,y;
const int mod=676767677;

int divCnt(int d){
    int res=1;
    for(int i=2;i*i<=d;i++){
        int cnt=0;
        while(d%i==0)d/=i,cnt++;
        if(cnt>0)res*=(cnt+1);
    }
    if(d>1)res*=2;
    return res;
}

signed main(){
    cin>>_;
    while(_--){
        cin>>x>>y;
        int d=abs(x-y);
        if(d==0){
            cout<<1<<endl;    
        }
        else cout<<divCnt(d)%mod<<endl;       
            if(x>=y){
                for(int i=0;i<x;i++)cout<<1<<" ";
                for(int i=0;i<y;i++){
                    cout<<-1<<" ";
                } 
            }else{
                for(int i=0;i<y;i++)cout<<-1<<" ";
                for(int i=0;i<x;i++){
                    cout<<1<<" ";
                }
            }
        
        cout<<endl;
    }
}