#include <iostream>
#include <vector>
#include <cstdlib>
#include <random>
using namespace std;

void handle(vector<int> &arr, int min, int max)
{
    int mid = min + ((max - min) >> 1);
    if(arr[min] > arr[mid]) swap(arr[mid], arr[max]);
    if(arr[min] > arr[max]) swap(arr[min], arr[max]);
    if(arr[mid] > arr[max]) swap(arr[mid], arr[max]);
    swap(arr[mid], arr[max]);
    return;
}

vector<int> partition(vector<int> &arr, int pl, int pr)
{
    int base = arr[pr];
    while(pl < pr)
    {
        while(pl < pr && arr[pl] < base) ++pl;
        if(arr[pl] > base)
        {
            swap(arr[pl], arr[pr]);
            --pr; 
        }
        while(pl < pr && arr[pr] > base) --pr;
        if(arr[pr] < base)
        {
            swap(arr[pl], arr[pr]);
            ++pl;
        }
    }
    vector<int> ret(2);
    ret[0] = pl;
    ret[1] = pr;
    return ret;
}


void quick_sort_v1(vector<int> &arr, int l, int r)
{
    if(r <= l) return;
    
    handle(arr, l, r);
    vector<int> border_num = partition(arr, l, r);
    quick_sort_v1(arr, l, border_num[0] - 1);
    quick_sort_v1(arr, border_num[1] + 1, r);
}


int main()
{
    vector<int> arr;
    for(int i = 10;i > 0;--i)
    {
        arr.push_back(i);
    }
    quick_sort_v1(arr, 0, 9);
    for(auto it : arr) 
    {
        cout << it << " ";
    }
    return 0;
}
