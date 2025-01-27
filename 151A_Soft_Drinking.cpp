#include<iostream>
#include<algorithm>

using namespace std;
int main()
{
    int n,k,l,c,d,p,nl,np;
    cin>>n>>k>>l>>c>>d>>p>>nl>>np;

    int drink_toast=(k*l)/nl;
    int limes_toast=(c*d);
    int salt_toast=p/np;

    int total_toast=min({drink_toast,limes_toast,salt_toast});
    int toast=total_toast/n;

    cout<<toast<<endl;
    
}
