#include <iostream>
#include <vector>
#include <string>
using namespace std;
void get_nextarr(vector<int> &next, const string s2)
{
    if(next.size() == 1)
    {
        next[0] = -1;
        return;
    }
    next[0] = -1;
    next[1] = 0;
    int i = 2;
    int cn = 0;
    while(i < next.size())
    {
        if(s2[i] == s2[cn]) next[i++] = ++cn;
        else if(cn > 0) cn = next[cn];
        else next[i++] = 0;
    }
    return;
}
int KMP_str(string s1, string s2)
{
    if(s1.size() == 0 || s2.size() == 0 || s2.size() < 1 || s1.size() < s2.size()) return -1;
    vector<int> next(s2.size());
    get_nextarr(next, s2);
    int i1 = 0;
    int i2 = 0;
    while(i1 < s1.size() && i2 < s2.size())
    {
        if(s1[i1] == s2[i2])
        {
            ++i1;
            ++i2;
        }
        else if(next[i2] == -1)
        {
            ++i1;
        }
        else
        {
            i2 = next[i2];
        }
    }
    return i2 == s2.size() ? i1 - i2 : -1;
}

int main()
{
    return 0;
}
