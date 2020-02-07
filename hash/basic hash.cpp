#include <iostream>
#include <bits/stdc++.h>
using namespace std;

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define pii pair<int, int> 
#define pll pair<long long int, long long int>
#define sci(x) scanf("%d", &x)
#define scl(x) scanf("%lld", &x)
#define fi first
#define sc second







void printarray(int arr[],int r){
    for (int i = 0; i < r; i++) {
        cout<<arr[i];
    }
    cout<<endl;
}
int main() {

 
 
	int n;
	cin>>n;
	int size = n ;
	string arr[n];
	
    for (int i = 0; i < n; i++) {
        
        int temp ; 
        cin>>temp ;
        
        cin>>arr[temp%n] ;
      
    }

    int out;
    cin>>out;    

    while(out--){
        int temp;
        cin>>temp;
    
        cout<<arr[temp%n]<<endl;
        
    }
 
 
 
 

	return 0;
}
