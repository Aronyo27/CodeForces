#include<bits/stdc++.h>
using namespace std;
int a=0,b,c,x,y,z,n;

int32_t main(){
    int _;cin>>_;
    while(_--){
        cin>>n;
        int h=n;
        for(int i=0;i<=n;i++){
            while(i*i+h*h>=(n+1)*(n+1)){
                h--;
            }
            x=h;
            while(i*i+x*x>=n*n && x>0){
                x--;a++;
            }
        }
        cout<<4*a<<endl;
        a=0;
    }
    return 0;
}