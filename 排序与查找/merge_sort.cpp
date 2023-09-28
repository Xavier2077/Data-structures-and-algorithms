#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1000;
int arr[MAXN];
int n;

void merg_sort(int s, int e)
{
	if(s >= e) return;
	int mid = (s + e) >> 1;
	merg_sort(s, mid);
	merg_sort(mid + 1, e);
	int tmp[MAXN];
	int l = s, r = mid + 1, k = s;
	while(l <= mid || r <= e)
	{
		if(r > e || (l <= mid && arr[l] <= arr[r]) )
		{
			tmp[k++] = arr[l++];
		}
		else
		{
			tmp[k++] = arr[r++];
		}
	}
	for(int i = s;i <= e;++i)
	{
		arr[i] = tmp[i];
	}
	return;
}

int main()
{
	scanf("%d", &n);
	for(int i = 0;i < n;++i)
	{
		scanf("%d", &arr[i]);
	}
	merge_sort(0, n - 1);
	for(int i = 0;i < n;++i)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
