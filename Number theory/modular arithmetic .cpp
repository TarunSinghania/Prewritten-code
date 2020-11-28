///normal x^n


int recursivePower(int x,int n)
{
    if(n==0)
        return 1;
    return x*recursivePower(x,n-1);
}


int iterativePower(int x,int n)
{
    int result=1;
    while(n>0)
    {
        result=result*x;
        n--;
    }
    return result;
}



//optimised
int binaryExponentiation(int x,int n)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return binaryExponentiation(x*x,n/2);
    else                             //n is odd
        return x*binaryExponentiation(x*x,(n-1)/2);
}


0(log n)


int binaryExponentiation(int x,int n)
{
    int result=1;
    while(n>0)
    {
        if(n % 2 ==1)
            result=result * x;
        x=x*x;
        n=n/2;
    }
    return result;
}



int modularExponentiation(int x,int n,int M)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return modularExponentiation((x*x)%M,n/2,M);
    else                             //n is odd
        return (x*modularExponentiation((x*x)%M,(n-1)/2,M))%M;

}


0(logn)

//wrong
int modularExponentiation(int x,int n,int M)
{
    int result=1;
    while(n>0)
    {
        if(n % 2 ==1)
            result=(result * x)%M;
        x=(x*x)%M;
        n=n/2;
    }
  

 	  return result;


}



long long int modularExponentiation(long long int x,long long int n,long long int M)
{
long long int result=1;
while(n>0)
{
if(n % 2 ==1)
result=(result * x)%M;
x=(x*x)%M;
n=n/2;
}
return result;
}


#include <bits/stdc++.h>
using namespace std;
 
long long int m=1000000007;


//string mod 
long long int conver(string s,long long int mod)
{
    long long int i,ans=0;
    for(i=0;i<s.size();i++)
    {
        ans=(ans*10+(s[i]-48))%(mod);
    }
    return ans;
}


void extendedEuclid(long long int c,long long int m)
{
if(m == 0)
{
d = c;
z = 1;
y = 0;
}
else
{
extendedEuclid(m, c%m);
long long int temp = z;
z = y;
y = temp - (c/m)*y;
}
}

ll d, x, y,z;

long long int modInverse(long long int c, int M)
{
extendedEuclid(c,M);
return (z%M+M)%M;
}




//for primes use fermat little theorem 
int modInverse(int A,int M)
{
    return modularExponentiation(A,M-2,M);
}



