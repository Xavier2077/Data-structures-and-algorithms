#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_OP 20
#define swap(a, b) {int t=a;a=b;b=t;}
void select_sort(int* arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[index] > arr[j])
                index = j;
        }
        swap(arr[index], arr[i]);
    }
    return;
}
void quick_sort(int* arr, int l, int r)
{
    if (r <= l)
        return;
    int x = l;
    int y = r;
    int z = arr[l];
    while (x < y)
    {
        while (x<y && arr[y]>=z)
        {
            y--;
        }
        if (arr[y] < z)
        {
            arr[x] = arr[y];
            x++;
        }
        while (x < y && arr[x] <= z)
        {
            x++;
        }
        if (arr[x] > z)
        {
            arr[y] = arr[x];
            y--;
        }
    }
    arr[x] = z;
    quick_sort(arr,l, x - 1);
    quick_sort(arr,x + 1, r);
     
    return;
}
void output(int* arr, int n)
{
    printf("[");
    for (int i = 0; i < n; ++i)
    {
        printf(" %d", arr[i]);
    }
    printf(" ]\n");
}
int main() 
{
    srand(time(0));
    int* p = (int*)malloc(sizeof(int) * MAX_OP);
    for (int i = 0; i < MAX_OP; ++i)
    {
        p[i] = rand() % 100;
    }
    //select_sort(p, MAX_OP);
    //output(p, MAX_OP);
    quick_sort(p, 0, MAX_OP - 1);
    output(p, MAX_OP);
    return 0;
}
