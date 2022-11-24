//取反，0->1, 1->0
int flip(int x)
{
    return x ^ 1;
}
//获取数字的符号，正数返回1，负数返回0
int sign(int x)
{
    return flip((x >> 31) & 1);
}
//方法1
int get_max(int a, int b)
{
    int c = a - b;//如果b为负数，可能有溢出风险
    int scA = sign(c);
    int scB = flip(scA);
    return scA * a + scB * b;
    //互斥事件中的或用加法同等表示
}
优化
int get_max2(int a, int b)
{
    int c = a - b;
    int sa = sign(a);
    int sb = sign(b);
    int sc = sign(c);
    int disSab = sa ^ sb;
    int sameSab = flip(disSab);
    int returnA = sa * disSab + sc * sameSab;
    int returnB = flip(returnA);
    return returnA * a + returnB * b;
}
