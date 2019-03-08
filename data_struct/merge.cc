//用分治思想处理一个数组中逆序对的个数

#include <iostream>
using namespace std;

int merge (int A[], int begin, int mid, int end)
{
    static int count = 0;
    int result[end - begin + 1];
    int i = begin;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= end)
    {
        if (A[i] <= A[j])
        {
            result[k++] = A[i++];
        } else {
            count += (mid - i + 1);
            result[k++] = A[j++];
        }
    }
    while (j <= end)
    {
        result[k++] = A[j++];
    }
    while (i <= mid)
    {
        result[k++] = A[i++];
    }
    for(k = 0; k < (end-begin+1); k++)
    {
        A[begin + k] = result[k];
    }
    return count;
}

int mergeSort(int a[], int begin, int end)
{
    int sum = 0;
    if (begin < end)
    {
        int mid = (begin + end)/2;
        mergeSort (a, begin, mid);
        mergeSort (a, mid + 1, end);
        sum = merge (a, begin, mid, end);
    }
    return sum
}

int main()
{
    return 0;
}

