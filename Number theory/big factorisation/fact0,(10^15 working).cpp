#include <bits/stdc++.h> 
using namespace std;
#define MAXL (500000>>5)+1
#define GET(x) (mark[x>>5]>>(x&31)&1)
#define SET(x) (mark[x>>5] |= 1<<(x&31))
#define ll long long
#define pb push_back
ll me(ll x,ll n){
  ll r= 1;
  while(n > 0){
    if(n%2 == 1)
      r = r * x;
    x = x*x;
    n = n/2;
  }
  return r;
}
const long long mx = 10000005;
long long  spf[mx];
void sieve2()
{
    for(int i=1;i<mx;i++) spf[i] = i;
    for(int i=2;i<mx;i+=2) spf[i] = 2;
    int sq = sqrt(mx);
    for(int i=3;i<=sq;i++)
    {
        if(spf[i]==i)
        {
            for(int j=i*i;j<mx;j+=i)
            {
                if(spf[j]==j)
                {
                    spf[j] = i;
                }
            }
        }
    }
}
void spf_factorize(long long n, vector<long long> &f) {
    while(n!=1){
      f.pb(spf[n]);
      n = n/spf[n];
    }
}
int mark[MAXL];
int P[500000], Pt = 0;
void sieve() {
    ll i, j, k;
    SET(1);
    int n = 463400;
    for (i = 2; i <= n; i++) {
        if (!GET(i)) {
            for (k = n/i, j = i*k; k >= i; k--, j -= i)
                SET(j);
            P[Pt++] = i;
        }
    }
}
long long mul(unsigned long long a, unsigned long long b, unsigned long long mod) { 
    long long ret = 0; 
    for (a %= mod, b %= mod; b != 0; b >>= 1, a <<= 1, a = a >= mod ? a - mod : a) {
        if (b&1) {
            ret += a;
            if (ret >= mod) ret -= mod;
        }
    } 
    return ret; 
}
void exgcd(long long x, long long y, long long &g, long long &a, long long &b) {
    if (y == 0)
        g = x, a = 1, b = 0;
    else
        exgcd(y, x%y, g, b, a), b -= (x/y) * a;
}
long long llgcd(long long x, long long y) {
    if (x < 0)    x = -x;
    if (y < 0)    y = -y;
    if (!x || !y)    return x + y;
    long long t;
    while (x%y)
        t = x, x = y, y = t%y;
    return y;
}
long long inverse(long long x, long long p) {
    long long g, b, r;
    exgcd(x, p, g, r, b);
    if (g < 0)  r = -r;
    return (r%p + p)%p;
}
long long mpow(long long x, long long y, long long mod) { // mod < 2^32 
    long long ret = 1;
    while (y) {
        if (y&1) 
            ret = (ret * x)%mod;
        y >>= 1, x = (x * x)%mod;
    }
    return ret % mod;
}
long long mpow2(long long x, long long y, long long mod) {
    long long ret = 1;
    while (y) {
        if (y&1) 
            ret = mul(ret, x, mod);
        y >>= 1, x = mul(x, x, mod);
    }
    return ret % mod;
}
int isPrime(long long p) { // implements by miller-babin
    if (p < 2 || !(p&1))  return 0;
    if (p == 2)       return 1;
    long long q = p-1, a, t;
    int k = 0, b = 0;
    while (!(q&1))  q >>= 1, k++;
    for (int it = 0; it < 2; it++) {
        a = rand()%(p-4) + 2;
        t = mpow2(a, q, p);
        b = (t == 1) || (t == p-1);
        for (int i = 1; i < k && !b; i++) {
            t = mul(t, t, p);
            if (t == p-1)
                b = 1;
        }
        if (b == 0)
            return 0;
    }
    return 1;
}
long long random(long long x,long long n,long long c){
        x = (mul(x, x, n) + c);
        if (x >= n) x -= n;
        return x;
}

long long pollard_rho(long long n, long long c) {
    long long x = 2, y = 2, i = 1, k = 2, d;
    x = random(x,n,c);
    y = random(random(y,n,c),n,c);

    ll exe = 0;

    while (x!=y) {
       
        //x = (mul(x, x, n) + c);
        //if adding c make  the number larger than n
        //if (x >= n) x -= n;
        d = llgcd(abs(x - y), n);
        //found something that divides both x-y and n
        if (d > 1) return d;
        //flyod wasrhall cycle detection
       // if (++i == k) { y = x, k <<= 1;}
      x = random(x,n,c);
      y = random(random(y,n,c),n,c);
    }
    return n;
}
void factorize(int n, vector<long long> &f) {
    for (int i = 0; i < Pt && P[i]*P[i] <= n; i++) {
      if (n%P[i] == 0) {
        while (n%P[i] == 0)
          f.push_back(P[i]), n /= P[i];
      }
    }
    if (n != 1) f.push_back(n);
}
void llfactorize(long long n, vector<long long> &f) {
    if (n == 1) 
        return ;  
    if(n < 1e7){
      spf_factorize(n,f);
      return;
    }
    if (n < 1e+9) {
        factorize(n, f);
        return ;
    }
    if (isPrime(n)) {
        f.push_back(n);
        return ;
    }
    long long d = n;
    for (int i = 2; d == n; i++)
        d = pollard_rho(n, i);
    //gives us a factor n = d*whatever (if available)
    llfactorize(d, f);
    llfactorize(n/d, f);
}

int main() {
    sieve();
    sieve2();
    long long testcase;
    cin>>testcase;
    while (testcase!=0) {
        long long n;
        n = testcase;
        vector<long long> f;
        map<long long, int> r;
            
        llfactorize(n, f);
        for (auto &x : f)
            r[x]++;
        for (auto it = r.begin(); it != r.end(); it++) {
            if (it != r.begin())
                printf(" ");
            printf(" %lld", it->first);
            if (it->second > 0)
                printf("^%d", it->second);
        }
        cout<<endl;
        cin>>testcase;

    }
    return 0;
}