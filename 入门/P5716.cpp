#include<iostream>
using namespace std;
int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool isrun(int y)
{
    if(y%4==0&&y%100!=0||y%400==0)
    {
        return true;
    }
    return false;
}
int main()
{
    int y,m;
    cin>>y>>m;
    int ans=0;
    if(isrun(y))
    {
        month[2]=29;
    }
    cout<<month[m];
    return 0;
}