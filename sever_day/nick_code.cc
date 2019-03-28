//每次读取一个数之后，算出他经过ｋ次洗牌后的位置，只用一个长度为2n数组用来输出
//根据当前数的位置，可以算出经过一次洗牌后的位置
//如果当前数小于等于N(即在左手)，则他下次出现的位置是　２＊当前位置
//与之对应的当前位置　＋Ｎ（即在右手）的牌，则他下次出现的位置是　２＊当前位置　＋１

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T, n, k;
    cin >> T;
    while (T--)
    {
        cin >> n >> k;
        int num = 2 * n;
        vector<int> table(num);
        for (int i = 0; i < num; ++i)
            cin >> table[i];
        //洗ｋ次牌
        while (k--)
        {
            vector<int> n1(table.begin(), table.end());
            for (int i = 0; i < n; ++i)
            {
                //如果当前数小于等于n（即在左手），则他下次出现的位置是２＊当前位置
                //与之对应的当前位置＋ｎ（即在右手）的牌，则他下次出现的位置是2*当前位置＋１
                table[2*i] = n1[i];
                table[2*i + 1] = n1[i + n];
            }
        }

        for (int i = 0; i < num - 1; ++i)
            cout << table[i] << " ";
        cout << table[num - 1] << endl;
    }
    return 0;
}


