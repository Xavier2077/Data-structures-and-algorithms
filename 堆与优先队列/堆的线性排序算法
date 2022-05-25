#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define swap(a,b){int t = a;a = b;b = t;}
void downUpdate(int* arr, int n, int ind)
{
	while ((ind << 1) <= n)
	{
		int temp = ind;
		int l = ind << 1;
		int r = ind << 1 | 1;
		if (arr[l] > arr[temp])
		{
			temp = l;
		}
		if (r <= n && arr[r] > arr[temp])
		{
			temp = r;
		}
		if (temp == ind)
		{
			break;
		}
		swap(arr[temp], arr[ind]);
		ind = temp;
	}
	return;
}
//线性建堆法
void heap_sort(int* arr, int n)
{
	arr -= 1;//使得下标从1开始
	for (int i = n >> 1; i >= 1; i--)
	{
		downUpdate(arr, n, i);
	}
	for (int i = n; i > 1; i--)
	{
		swap(arr[1], arr[i]);
		downUpdate(arr, i - 1, 1);
	}
	return;
}
void output(int* arr, int n) {
	printf("arr[%d] = [", n);
	for (int i = 0; i < n; i++) {
		printf(" %d", arr[i]);
	}
	printf("]\n");
	return;
}

int main()
{
	srand(time(0));
#define MAX_OP 20
	int* arr = (int*)malloc(sizeof(int) * MAX_OP);
	for (int i = 0; i < MAX_OP; i++)
	{
		arr[i] = rand() % 100;
	}
	output(arr, MAX_OP);
	heap_sort(arr, MAX_OP);
	output(arr, MAX_OP);

	return 0;
}
