Return iterator to lower bound
Returns an iterator pointing to the first element in the range [first,last) which does not compare less than val.(equal or greater )

upper_bound:::::::::

eturns an iterator pointing to the first element in the range [first,last) which compares greater than val.

The elements are compared using operator< for the first version, and comp for the second. The elements in the range shall already be sorted according to this same criterion (operator< or comp), or at least partitioned with respect to val.

The function optimizes the number of comparisons performed by comparing non-consecutive elements of the sorted range, which is specially efficient for random-access iterators.

Unlike lower_bound, the value pointed by the iterator returned by this function cannot be equivalent to val, only greater.


// lower_bound/upper_bound example
#include <iostream>     // std::cout
#include <algorithm>    // std::lower_bound, std::upper_bound, std::sort
#include <vector>       // std::vector

int main () {
  int myints[] = {10,20,30,30,20,10,10,20};
  std::vector<int> v(myints,myints+8);           // 10 20 30 30 20 10 10 20

  std::sort (v.begin(), v.end());                // 10 10 10 20 20 20 30 30

  std::vector<int>::iterator low,up;
  low=std::lower_bound (v.begin(), v.end(), 20); //          ^
  up= std::upper_bound (v.begin(), v.end(), 20); //                   ^

  std::cout << "lower_bound at position " << (low- v.begin()) << '\n';
  std::cout << "upper_bound at position " << (up - v.begin()) << '\n';

  return 0;
}




  fr(i,1,n)
  cin>>a[i];

 sort(a,a+n);


 int* t = upper_bound(a,a+n,p);

  if(t == a)
    cout<<0<<" "<<0<<endl;
    else if(*t!=a[n])
    cout<<t-a<<" "<<s[t-a -1]<<endl;
    else
    cout<<n<<" "<<s[n-1]<<endl;


  lower bound implementation 


     #include <bits/stdc++.h>

using namespace std;

#define fr(i,a,b) for(int i =a ; i < b; i++)
#define mkp make_pair 
#define pb push_back
#define pii pair<int,int>
#define speed   ios::sync_with_stdio(false), cin.tie(0) , cout.tie(0)
#define c(a,b) cout<<a<<"--"<<b<<endl;
#define frv(i,a,v) for(int i =  a ; i < v.size() ; ++i)
#define cp(a,i)  cout<<a[i].first<<" "<<a[i].second<<endl;


int lowerbound(int arr[],int start ,int end , int value)
{

    int low = start;
    int high = end ;

    while(low<high)
    {

      int mid = (low +high)>>1;

      if(arr[mid] < value) //put here euals yo for upperbound
        low=mid+1;
      else
        high = mid;

    }

    if(high == end && value < arr[end])
      return -1;
    else
      return low ;



}

int main()
{



int n ;
cin>>n;
int a[n],s[n];

cin>>a[0];
s[0] = a[0];

fr(i,1,n)
{
  cin>>a[i];
  s[i]=a[i]+s[i-1];
}


//fr(i,0,n)
//cout<<s[i]<<" s"<<i<<endl; 
  

int q ;
cin>>q;
//cout<<q<<"www"<<endl;


while(q--)
{
    int k ;
    cin>>k;

    cout<<lowerbound(s,0,n-1,k)+1<<endl;
//lower_bound(s,s+n,k)-s poistion indexing from 0 ....

}
return 0 ;
}
