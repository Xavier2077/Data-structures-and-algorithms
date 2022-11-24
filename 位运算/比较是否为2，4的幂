//判断是否为2，4的幂
bool is2Power(int n)
{
    return n > 0 && n == (n & (~n + 1));//或者 n > 0 && (n & (n - 1)) == 0
    //再写条件时要注意括号，否则会有bug
}

bool is4Power(int n)
{
    return n >0 && ((n & (n - 1)) == 0) && (n & 0x55555555) != 0; //或者 (n & 0xaaaaaaaa) == 0
}
