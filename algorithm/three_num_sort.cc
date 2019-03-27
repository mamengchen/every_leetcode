//三整数排序
//输入３个整数，　
//20 7 33
//样例输出
//7 20 33

#include <iostream>
using namespace std;

int main()
{
    int a, b, c, t;
    cin >> a >> " " >> b >> " " >> c;
    if ( a > b )
    {
        t = a;
        a = b;
        b = t;
    }

    if ( a > c )
    {
        t = a;
        a = c;
        c = t;
    }

    if ( b > c )
    {
        t = b;
        b = c;
        c = t;
    }
    cout << a << " " << b << " " << c;
    return 0;

}
