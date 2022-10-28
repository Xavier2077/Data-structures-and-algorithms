#include <iostream>
using namespace std;
void radix(int* arr, int n)
{
    //处理low 16
    int* temp = new int[n];
    int cnt[65536] = {0};
    for(int i = 0;i < n;++i)
    {
        cnt[arr[i] & 0xffff] += 1;  //or cnt[arr[i] % 65536] += 1;
    }
    for(int i = 1;i < 65536;++i)
    {
        cnt[i] += cnt[i - 1];
    }
    for(int i = n - 1;i >= 0;--i)
    {
        temp[--cnt[arr[i] & 0xffff]] = arr[i];
    }
    //处理high 16
    for(int i = 0;i < 65536;++i) cnt[i] = 0;
    for(int i = 0;i < n;++i)
    {
        cnt[(arr[i] & 0xffff0000) >> 16] += 1; // or cnt[arr[i] / 65536] += 1;
    }
    for(int i = 1;i < 65536;++i)
    {
        cnt[i] += cnt[i - 1];
    }
    for(int i = n - 1;i >= 0;--i)
    {
        arr[--cnt[temp[i] & 0xffff0000]] = temp[i];
    }
    delete []temp;
    return;
}
#define MAX_SIZE 20
int main()
{
    int* arr[MAX_SIZE];
    return 0;
}
