
inline int add(int x,int y)
{
    if(x + y >= mod)
        return x + y - mod;
    return x + y;
}
inline int sub(int x,int y)
{
    if(x - y < 0)
        return x - y + mod;
    return x - y;
}
inline int mul(int x,int y)
{
    return 1LL * x * y % mod;
}