#include<iostream>
#include<set>
#include<string>
using namespace std;
int main()
{
    string line;
    cin>>line;

    set<char> unique_characters(line.begin(), line.end());

    int cnt= unique_characters.size();
    
    if (cnt%2==0)
    {
        cout<<"CHAT WITH HER!"<<endl;
    }
    else
    {
        cout<<"IGNORE HIM!"<<endl;
    }
    return 0;
}