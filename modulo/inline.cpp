
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


ll add(ll x,ll y){
	return (x+y)%MOD;
}
ll sub(ll x,ll y){
	return (x-y+MOD)%MOD;
}
ll mul(ll x,ll y){
	return (x*y)%MOD;
}