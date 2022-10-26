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
