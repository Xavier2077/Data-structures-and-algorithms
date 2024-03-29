#include <iostream>
using namespace std;
class Solution {
public:
    class unionset
    {
    public:
        int* father;
        int n;
        unionset(int n)
        {
            father = new int[n + 1];
            this->n = n;
            for(int i = 0;i < n;++i)
            {
                father[i] = i;
            }
        }
        int get(int x)
        {
            return father[x] = (father[x] == x ? x : get(father[x]));
        }
        void merge(int a, int b)
        {
            father[get(a)] = get(b);
            return;
        }
        bool same(int a, int b)
        {
             return get(a) ==  get(b);
        }
    };
int main()
{
    return 0;
}
