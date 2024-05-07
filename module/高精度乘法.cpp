#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
struct bignum
{
    int num[1000];
    int len;
    bignum()
    {
        memset(num,0,sizeof(num));
        len=1;
    }
    bignum operator=(int b)
    {
        memset(num,0,sizeof(num));
        len=0;
        while(b>0)
        {
            len++;
            num[len]=b%10;
            b/=10;
        }
        return *this;
    }
    bignum operator+(const bignum &b)
    {
        bignum c;
        c.len=max(len,b.len);
        for(int i=1;i<=c.len;i++)
        {
            c.num[i]+=num[i]+b.num[i];
            c.num[i+1]+=c.num[i]/10;
            c.num[i]%=10;
        }
        if(c.num[c.len+1]>0)
        {
            c.len++;
        }
        return c;
    }
    bignum operator=(const bignum &b)
    {
        len=b.len;
        for(int i=1;i<=len;i++)
        {
            num[i]=b.num[i];
        }
        return *this;
    }
    bignum operator=(const char *b)
    {
        len=strlen(b);
        for(int i=1;i<=len;i++)
        {
            num[i]=b[len-i]-'0';
        }
        return *this;
    }
    bignum operator*(const int &b)
    {
        bignum c;
        c.len=len;
        for(int i=1;i<=len;i++)
        {
            c.num[i]+=num[i]*b;
            c.num[i+1]+=c.num[i]/10;
            c.num[i]%=10;
        }
        while(c.num[c.len+1]>0)
        {
            c.len++;
            c.num[c.len+1]+=c.num[c.len]/10;
            c.num[c.len]%=10;
        }
        return c;
    }
    bignum operator*(const bignum &b)
    {
        bignum c;
        c.len=len+b.len;
        for(int i=1;i<=len;i++)
        {
            for(int j=1;j<=b.len;j++)
            {
                c.num[i+j-1]+=num[i]*b.num[j];
                c.num[i+j]+=c.num[i+j-1]/10;
                c.num[i+j-1]%=10;
            }
        }
        while(c.num[c.len+1]>0)
        {
            c.len++;
            c.num[c.len+1]+=c.num[c.len]/10;
            c.num[c.len]%=10;
        }
        return c;
    }
    friend ostream &operator<<(ostream &out,const bignum &b)
    {
        for(int i=b.len-1;i>0;i--)
        {
            cout<<b.num[i];
        }
        return out;
    }
};
int main()
{
    char n[1000];
    cin>>n;
    bignum ans;
    ans=n;
    ans=ans*ans;
    cout<<ans;
}
