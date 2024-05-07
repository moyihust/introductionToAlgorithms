#include <iostream>
#include <cstring>
#include <cstdio>
const int LEN = 1000;
using namespace std;
struct bignum
{ /* data */
    int len;
    int num[LEN];
    bignum()
    {
        memset(num, 0, sizeof(num));
        len = 1;
    }
    bignum operator=(int b)
    {
        memset(num, 0, sizeof(num));
        len = 0;
        while (b > 0)
        {

            num[len] = b % 10;
            b /= 10;
            len++;
        }
        return *this;
    }
    bignum operator+(const bignum &b)
    {
        len = len > b.len ? len : b.len;
        for (int i = 0; i < LEN - 1; i++)
        {
            num[i] += b.num[i];
            if (num[i] >= 10)
            {
                num[i + 1] += num[i] / 10;
                num[i] %= 10;
            }
        }
        if (num[len] > 0)
            len++;
        return *this;
    }
    bignum operator*(const bignum &b)
    {
        bignum c;
        c.len = len + b.len - 1;
        for (int i = 0; i < len; ++i)
        {
            for (int j = 0; j < b.len; ++j)
            {
                c.num[i + j] += num[i] * b.num[j];
            }
        }
        // 处理进位
        for (int i = 0; i < c.len; ++i)
        {
            if (c.num[i] >= 10)
            {
                c.num[i + 1] += c.num[i] / 10;
                c.num[i] %= 10;
            }
        }
        // 如果最高位有进位，则长度加1
        if (c.num[c.len] > 0)
            c.len++;
        return c;
    }
    void print()
    {
        int i;
        for (i = len - 1; i >= 0; i--)
        {
            cout << num[i];
        }
        cout << endl;
    }
};

int main()
{
    int n;
    cin >> n;
    bignum ans, b;
    ans = 0;
    b = 1;
    bignum index;
    for (int i = 1; i <= n; i++)
    {
        index = i;
        b = b * index;
        ans = ans + b;
    }
    ans.print();
}