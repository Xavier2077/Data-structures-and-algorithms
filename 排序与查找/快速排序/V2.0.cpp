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

int partition(vector<int> &arr, int pl, int pr)
{
    int base = arr[pr];
    while(pl < pr)
    {
        while(pl < pr && arr[pl] <= base) ++pl;
        if(arr[pl] > base)
        {
            arr[pr] = arr[pl];
            --pr; 
        }
        while(pl < pr && arr[pr] > base) --pr;
        if(arr[pr] < base)
        {
            arr[pl] = arr[pr];
            ++pl;
        }
    }
    arr[pr] = base;
    return pr;
}


void quick_sort_v1(vector<int> &arr, int l, int r)
{
    if(r <= l) return;
    
    handle(arr, l, r);
    int ret = partition(arr, l, r);
    quick_sort_v1(arr, l, ret - 1);
    quick_sort_v1(arr, ret + 1, r);
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
