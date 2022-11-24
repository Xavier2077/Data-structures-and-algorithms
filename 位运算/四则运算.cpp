//实现两数的四则运算
//加
int add(int a, int b)
{
    int sum = 0;
    while(b != 0)
    {
        sum = a ^ b;//无进位相加 -> 相加结果
        b = (a & b) << 1;//进位信息
        a = sum;
    }
    return sum;
}
//减法
int neg_num(int n) //取相反数
{
    return add(~n, 1);
}
int minus1(int a, int b)
{
    return add(a, neg_num(b));//a - b == a + (-b)
}
//乘法
//可以使用十进制乘法公式
int multi(int a, int b)
{
    int res = 0;
    while(b != 0)
    {
        if((b & 1) != 0)
        {
            res = add(res, a);
        }
        a << 1;//a向前进位
        b >> 1;
    }
    return res;
}
//除法
bool isNeg(int n)
{
    return (n >> 31) & 1;
}
int div1(int a, int b)
{
    //确保a，b均为整数
    a = isNeg(a) ? neg_num(a) : a;
    b = isNeg(b) ? neg_num(b) : b;
    int res = 0;
    for(int i = 31;i > -1;i = minus1(i, 1))
    {
        if((a >> i) >= b)
        {
            res |= (1 << i);
            a = minus1(i, 1);
        }
    }
    return isNeg(a) ^ isNeg(b) ? neg_num(res) ? res;
}
