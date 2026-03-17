#include<bits/stdc++.h>
#define int double
using namespace std;

signed main(){
    double c;
    cin>>c;
    double l=0,r=1e9;//,dif=1e-12;
    for(int i = 0; i < 200; i++){
        double m=(l+r)/2.0;
        if(m*m +sqrt(m)<c)l=m+1;
        else r=m-1;
    }
    cout <<fixed<<setprecision(20)<<l<<endl;
    return 0;
}