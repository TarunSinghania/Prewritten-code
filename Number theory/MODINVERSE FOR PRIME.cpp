
#include<iostream> 
using namespace std; 

////oONLY IF MOD IS PTIME OR A, B ARE COPRIME

#define ll long long
#define MOD 1000000007

ll gcd(ll a, ll b); 

  
ll me(ll x,ll n)
{
    ll r=1;
    while(n>0)
    {
        if(n % 2 ==1)
        r=(r * x)%MOD;
        x=(x*x)%MOD;
        n=n/2;
    }
    return r ;
}

ll mi(ll a) 
{ 
    ll g = gcd(a,MOD); 
    if (g != 1) 
        return -1;
    else
    { 
        // If a and m are relatively prime, then modulo inverse 
        // is a^(m-2) mode m 
        return me(a,MOD-2); 
    } 
} 



ll gcd(ll a, ll b) 
{ 
    if (a == 0) 
        return b;

    return gcd(b%a, a); 
} 
  
// Driver Program 
int main() 
{ 
    int a = 50; 
    mi(a); 
    return 0; 
} 
