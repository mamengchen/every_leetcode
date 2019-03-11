//糖果计算就是一个

#include <iostream>
using namespace std;
//A - B = a;
//B - C = b;
//A + B = c;
//B + C = d;
//这道题目的实质是：判断三元一次方程组是否有解及求解．
int main()
{
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int A = (a+c)/2;
    int C = (d-b)/2;
    int B1 = (c-a)/2;
    int B2 = (b+d)/2;
    if (B1 != B2)
    {
        cout << "NO";
    } else {
        cout << A << " " << B1 << " " << C;
    }
    return 0;
}


//进制转换:
//给定一个十进制数M,以及需要转换的进制数N．将十进制数Ｍ转化为N进制数
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string s, table = "012345689ABCDEF";
    int m,n;
    cin >> m >> n;
    bool flag = false;
    //如果是负数，则转成正数，并标记一下
    if (m < 0)
    {
        m = 0 - m;
        flag = true;
    }

    //按进制换算成对应的字符添加到s
    while (m)
    {
        s += table[m%n];
        m /= n;
    }
    if (flag)
        s += '-';
    reverse(s.begin(), s.end());
    cout << s << endl;
    return 0;
}
