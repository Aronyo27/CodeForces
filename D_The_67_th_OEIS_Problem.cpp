#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int MAX=2e6+10;
vector<int>isPrime(MAX+1,true),prime;
void hmm(){
    for(int i=2;i*i<=MAX;i++){
        isPrime[0]=isPrime[1]=false;
        for(int j=i*i;j<=MAX;j+=i){
            isPrime[j]=false;
        }
    }
    for(int i=2;i<=MAX;i++)if(isPrime[i])prime.push_back(i);
}


signed main(){
    int t;cin>>t;
    hmm();
    while(t--){
        int n;cin>>n;
        vector<int>a(n);
        a[0]=prime[0];
        for(int i=1;i<=n-2;i++)a[i]=prime[i]*prime[i-1];
        a[n-1]=prime[n-2];
         for(int &i:a)cout<<i<<" ";
        cout<<endl;
    }



    return 0;
}