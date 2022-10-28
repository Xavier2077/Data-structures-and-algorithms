#include <iostream>
#include <vector>
#include <cstdlib>
#include <random>
using namespace std;

class Heap
{
    // int heapsize;
    vector<int> heap;
    public:
    Heap(vector<int> arr)
    {
        // heapsize = 0;
        for(auto x : arr)
        {
            heap_insert(x);
        }
    }
    void heap_insert(int x) //插入，向上调整
    {
        heap.push_back(x);
        // ++heapsize;
        int index = heap.size() - 1;
        while(heap[index] > heap[(index - 1) / 2])
        {
            swap(heap[index], heap[(index - 1) / 2]);
            // cout << heap[index] << ":" << heap[(index - 1) / 2] << endl;
            index = (index - 1) / 2;
        }
    }
    void heap_down(int num, int heapsize) //向下调整 heapify
    {
        int index = num;
        int left = index * 2 + 1;
        while(left < heapsize)
        {
            int largest = left + 1 && heap[left] < heap[left + 1] ? left + 1 : left;
            largest = heap[largest] > heap[index] ? largest : index;
            if(index == largest) break;
            swap(heap[index], heap[largest]);
            index = largest;
            left = largest * 2 + 1;
        }
    }
    void heap_sort()
    {
        int heapsize = heap.size() - 1;
        while(heapsize > 0)
        {
            swap(heap[0], heap[heapsize]);
            heapsize--;
            heap_down(0, heapsize);
        }
    }
    void output_heap()
    {
        for(auto x : heap)
        {
            cout << x << " ";
        }
    }
};

int main()
{
    vector<int> arr;
    for(int i = 10;i > 0;--i)
    {
        arr.push_back(i);
    }
    Heap h(arr);
    h.heap_sort();
    h.output_heap();
    // cout << "success!" << endl;
    return 0;
}
