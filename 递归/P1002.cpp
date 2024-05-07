#include<iostream>
using namespace std;
long long s[25][25];
bool a[25][25];
int n,m,x,y;
int main()
{
    cin>>n>>m>>x>>y;
    s[1][1]=1;
    n++;
	m++;
	x++;
	y++;
    a[x][y]=1;
    a[x+2][y+1]=1;
    a[x+1][y+2]=1;
    a[x-1][y+2]=1;
    a[x-2][y+1]=1;
    a[x-2][y-1]=1;
    a[x-1][y-2]=1;
    a[x+1][y-2]=1;
    a[x+2][y-1]=1;
    s[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
           if((i!=1||j!=1)&&!a[i][j]) s[i][j]=s[i-1][j]+s[i][j-1];
        }
    }
    cout<<s[n][m];
}