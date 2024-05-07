#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int index=1;
    for(int i=n;i>0;i--)
    {
        for(int j=0;j<i;j++)
        {
            if(index<10)
            {
                printf("0%d",index);
            }
            else
            {
                cout<<index;
            }
            index++;
        }
        cout<<endl;
    }
}