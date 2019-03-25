//三个空汽水瓶可以换一瓶汽水，可以借但是必须还
//测试用例：
//3 10 81 0
//输出实例：
//1 5  40 
#include <iostream>
#include <string>

using namespace std;

int calculateNum( int num )
{
    //总兑换数
    int sum = 0;
    while ( num > 1 )
    {
        //每三瓶换一瓶
        int result = num / 3;
        int reminder = num % 3;
        sum = sum + result;
        num = result + reminder;

        if ( num == 2 )
        {
            ++sum;
            break;
        }
    }
    return sum;
}

int main()
{
    int number;
    while ( cin >> number )
    {
        cout << calculateNum(number) << endl;
    }
    return 0;
}
