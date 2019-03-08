#include <iostream>
#include <ctime>
#include <cassert>
#include <algorithm>

using namespace std;

//partition过程，和快排的partition一样
template <typename T>
int _partition(T arr[], int l, int r)
{
    int p = rand()%(r-l+1) +1;
    swap(arr[l], arr[p]);

    int j = l;//[l+1...j]<p;[lt+1...r] > p;
    for (int i = l + 1; i <= r; i++)
    {
        if (arr[i] < arr[l])
        {
            swap(arr[i], arr[++j]);
        }
    }
    swap(arr[l], arr[j]);
    return j;
}

template <typename T>
int _selection(T arr[], int l, int r, int k)
{
    if (l == r)
    {
        return arr[l];
    }

    //partition之后，arr[p]的正确位置就在索引p上
    int p = _partition(arr, l, r);
    if (k == p) //如果k == p，直接返回arr[p]
    {
        return arr[p];
    } else if (k < p) {
        return _selection(arr, l, p-1, k);
    } else {
        //如果k > p,则需要在arr[p+1...r]中找第k-p-1小的元素
        //注意：由于我们传入_selection的依然是arr,而不是arr[p+1...r],
        //      所以传入的最后一个参数依然是k，而不是k-p-1
        return _selection(arr, p+1, r, k);
    }
}


//寻找arr数组中第k小的元素
//注意：在我们的算法中, k是从0开始索引的，即最小的元素是第0小元素，以此类推
//如果希望我们的算法中k的语意是从1开始的，只需要在整个逻辑开始进行k--即可，可以
template <typename T>
int selection(T arr[], int n, int k)
{
    assert(k >= 0 && k < n);
    srand(time(NULL));
    return _selection(arr, 0, n-1, k);
}

//寻找arr数组中第k小的元素，k从１开始索引，即最小元素是第１小元素，以此类推
template <typename T>
int selection2(T arr[], int n, int k)
{
    return selection(arr, n, k-1);
}
