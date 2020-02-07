#include<bits/stdc++.h>
using namespace std;

const int mx = 1000005;
const int mod1 = 1000000;
int spf[mx];


void seive()
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

int SumOfPrimeFactor(vector<int>& arr)
{
    int sum = 0;
    for(int i=0;i<arr.size();i++)
    {
        int x = arr[i];
        while(x!=1)
        {
            sum = (sum+spf[x])%mod1;
            int y = spf[x];
            while(x%y==0)
            {
                x/=y;
            }
        }
    }
    return sum;
}

int main()
{
    seive();
    vector<int> a(5);
    for(int i=0;i<5;i++) cin>>v[i];
    cout<<SumOfPrimeFactor(a);
}
