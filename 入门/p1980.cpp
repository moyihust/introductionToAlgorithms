#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;
int main()
{
    int n,x;
    cin>>n>>x;
    stringstream ss;
    for(int i=1;i<=n;i++)
    {
        ss<<i;
    }
    string s=ss.str();
    cout<<count(s.begin(),s.end(),x+'0');
}