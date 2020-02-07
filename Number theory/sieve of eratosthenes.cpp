// C++ program to print all primes smaller than or equal to
// n using Sieve of Eratosthenes
#include <bits/stdc++.h>
using namespace std;
 
 
 void printprimes(bool arr[],int r){
     
 for (int i = 0; i < r; i++) {

         if(arr[i]==1)
        cout<<i<<" ";
            
                }
        cout<<endl;
     
 }
void printarray(bool arr[],int r){
    
    for (int i = 0; i < r; i++) {
    
        cout<<arr[i];
    }
    cout<<endl;
}

void SieveOfEratosthenes(int n, bool prime[] )
{

    memset(prime, true, n+1);
    
    prime[0]=false;
    prime[1]=false;

    for (int p=2; p*p<=n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
 

}
 
// Driver Program to test above function
int main()
{
    int n;
    cin>>n;
    //cout << "Following are the prime numbers smaller "
        // << " than or equal to " << n << endl;
   bool arr[n+1] ; 
   
SieveOfEratosthenes(n,arr);
 
    printprimes(arr,n+1);  
    return 0;
}






















#include <iostream>

#include <vector>

#include <algorithm>

#define FOR(i,a,b) for(int i=a;i<b;++i)
using namespace std ;

void SieveOfEratosthenes(int n, vector<int> &vect)

{
    bool prime[n+1] ;
    memset(prime, true, n+1);
    
    prime[0]=false;
    prime[1]=false;

    for (int p=2; p*p<=n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
    
    for(int i = 0 ; i < n+1 ; i++)
    {
        if(prime[i] == true)
        vect.push_back(i);
    }
 
 

}

int main()
{
   
    vector <int> arr ; 
    SieveOfEratosthenes(120,arr);
    
    return 0;
}   