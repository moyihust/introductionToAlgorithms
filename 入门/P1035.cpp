#include<iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    double sum=0;
    for(int i=1;;i++)
    {
        sum+=1.0/i;
        if(sum>n)
        {
            cout<<i;
            break;
        }
    }
}