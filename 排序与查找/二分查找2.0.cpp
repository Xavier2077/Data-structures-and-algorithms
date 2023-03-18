#include <iostream>
using namespace std;

int arr[7] = {0, 0, 0, 1, 1, 1, 1};
int binary_search(int l, int r, int target)//查找第一个>= 1的元素,即查找第一个1
{
    while(l + 1 != r)
    {
        int mid = l + r >> 1;
        if(arr[mid] < target) l = mid;
        else r = mid;
    }
    return r;
}
int binary_search2(int l, int r, int target)//查找最后一个小于1的元素，即查找最后一个0
{
    while(l + 1 != r)
    {
        int mid = l + r >> 1;
        if(arr[mid] > target) r = mid;
        else l = mid;
    }
    return l;
}

int main()
{
    int res = binary_search2(-1, 7, 1);
    printf("%d\n", res);
    return 0;
}
