#include<iostream>


using namespace std;
int main()
{   
    int year;
    cin>>year;
    string s;
    while (1)
    {
        year++;
        s=to_string(year);
            if (s[0]!=s[1] && s[0]!=s[2] && s[0]!=s[3] && s[1]!=s[2] && s[1]!=s[3] && s[2]!=s[3])
            {
                cout<<s<<endl;
                break;
            }       
    }
    return 0;
}