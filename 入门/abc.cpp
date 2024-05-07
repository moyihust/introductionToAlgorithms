#include<iostream>
#include<algorithm>
using namespace std;
int a[3];
char s[4];
int main()
{
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    cin>>s;
    for(int i=0;i<3;i++)
    {
        cout<<a[s[i]-'A']<<' ';
    }
    return 0;
}