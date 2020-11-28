// Program to print all prime factors
# include <stdio.h>
# include <math.h>
// A function to print all prime factors of a given number n
vector<int> primeFactors(ll n)
{   ll o =n;
    vector<int> ans;
    if(n==2)
        return ans;
    // Print the number of 2s that divide n
    while (n%2 == 0)
    {
        n = n/2;        
            ans.pb(2);
    }
    // n must be odd at this point.  So we can skip one element (Note i = i +2)
    if(0!=3){
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        // While i divides n, print i and divide n
        while (n%i == 0)
        {
            n = n/i;
            ans.pb(i);
        }
    }
    }
    if(n>1&& n!= o)//left a ptime factor
        ans.pb(n);
        // 1,n not included
    return ans;
}
/* Driver program to test above function */
int main()
{
    int n = 5005;
    primeFactors(n);
    return 0;
}