//这是实现三路快排的demo：三路快排用于有重复数的快排

#include <iostream>


//三路快速排序处理arr[l...r]
//将arr[l...r]分为 <v ; ==v ; >v 三部分
//之后递归对<v ; >v 两部分继续进行三路快排
template <typename T>
void _quickSort3Ways(T arr[], int l, int r)
{
    if (r - l <= 15)
    {
        //这里用插入排序，
        return;
    }

    //partition保证选取的数是随机的
    swap( arr[l], arr[rand()%(r-l+1)+l]);
    T v = arr[l];

    int lt = l;//arr[l+1...lt] < v
    int gt = r + 1; //arr[gt....r] > v
    int i = l + 1; //arr[lt+1...i] == v
    while (i < gt)
    {
        if (arr[i] < v)
        {
            swap(arr[i], arr[lt+1]);
            lt++;
            i++;
        } else if (arr[i] > v) {
            swap(arr[i], arr[gt-1]);
            gt--;
        } else {
            i++;
        }
    }

    swap(arr[l], arr[lt]);
    _quickSort3Ways(arr, l, lt-1);
    _quickSort3Ways(arr, gt, r);
}

template <typename T>
void quickSort3Ways(T arr[], int n)
{
    srand(time(NULL));
    _quickSort3Ways(arr, 0, n-1);
}
