//一个非排序的数组最少可以分成多少个排序的数组
//示例：
//6
//1 2 3 2 2 1
//输出：
//2
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<n> v;
    v.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }
    //找出波峰波谷
    int ret = 1;
    for (int i = 1; i < n-1; ++i)
    {
        if ((v[i-1] < v[i] && v[i] > v[i+1])
            || (v[i-1] > v[i] && v[i] < v[i+1]))
        {
            ret++;
            //如果发现波峰或者波谷，这里i++已经比过了，则需要跳过但是要注意越界．
            if (i != n-3)
            {
                i++;
            }
        }
    }
    cout << ret << endl;
    return 0;
}


//将一句话的单词进行倒置，标点不倒置．
//示例:
//I like beijing.
//输出:
//beijing. like I
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    //翻转整个句子
    reverse(s.begin(), s.end());
    //翻转单词
    auto start = s.begin();
    while (start != s.end())
    {
        auto end = start;
        while (end != s.end() && *end != ' ')
        {
            end++;
        }
        reverse(start, end);
        if (end != s.end())
            start = end + 1;
        else
            start = end;
    }
    cout << s << endl;
    return 0;
}
