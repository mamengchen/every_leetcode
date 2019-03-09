//字符串中找出连续最长的数字串

#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str,res,cur;
    cin >> str;
    for(int i = 0; i <= str.length(); i++)
    {
        //数字+=到cur
        if (str[i] >= '0' && str[i] <= '9')
        {
            cur += str[i];
        } else {
            //找出最长的字符串，则更新字符串
            if (res.length() < cur.length())
            {
                res = cur;
            } else {
                cur.clear();
            }
        }
    }
    cout << res;
    return 0;
}

//n个数里出现次数大于等于n/2的数
//因为要找过半的数，用一个变量count记录读取每个变量变化的次数，
//一个变量temp记录可能过半的数，先让temp=vec[0],
//然后往后遍历一遍，碰到和temp相同的数就给count++,否则就count--
//如果，count变成0，就让temp=vec[i]（vec数组遍历过程当前值），
//并让count=1如此遍历一遍，因为有一个数过半，所以temp最后肯定存储的是过半的数
#include <vector>
#include <iostream>
using namespace std;
int main()
{
    int n;
    vector<int> vec;
    while (cin >> n)
    {
        vec.push_back(n);
    }

    int count = 1;
    int temp = vec[0];
    for (int i = 1; i < vec.size(); ++i)
    {
        if (vec[i] == temp)
        {
            count++;
        } else {
            count--;
        }

        if (count == 0)
        {
            temp = vec[i];
            count++;
        }
    }
    cout << temp << endl;
    return 0;
}
