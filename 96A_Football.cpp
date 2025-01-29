#include<bits/stdc++.h>
using namespace std;

int main()
{
    string team;
    cin>>team;

    int count=1;
    bool an=false;

    for (int i = 1; i <team.size(); i++)
    {
        if(team[i]==team[i-1]) 
        {
            count++;
            if(count==7) 
            {
                an=true;
                break;
            }
        }
        else {count=1;}
    }
    if(an) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
