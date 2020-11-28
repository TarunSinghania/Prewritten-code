#include<bits/stdc++.h>
using namespace std;

#define fr(i,a,b) for(int i = a ; i<b;i++)
#define pii pair<int,int> 
 

 bool mycomp(pii a,pii b)
	{
		return a.first < b.first ;
	}


void print(stack< pair<int,int> > stack) {

    while(!stack.empty())
    {
        cout<<stack.top().first<<" " <<stack.top().second<<" ";
        stack.pop();

    }
    cout<<endl;
}

template <typename T1, typename T2, typename T3> void 
 print (pair<T1,T2> arr[] , T3 size) {

 	fr(i,1,size)
 	cout<<arr[i].first<<" "<<arr[i].second<<" "<<endl;



 }

int main(){
	
int n ;
cin>>n;
int arr[n+1];

fr(i,1,n+1)
cin>>arr[i];

pair<int,int> s[n] ;

fr(i,1,n+1)
s[i]=make_pair(arr[i],i);

sort(s,s+n+1,mycomp);

stack< pair<int,int> > s1 ;

for(int i = n ; i >0 ;i--)
s1.push(s[i]);



int fi[n+1]={0};
int gi[n+1]={0};


fr(i,1,n+1)
cout<<i<<" "<<fi[i]<<" "<<gi[i]<<endl;
print(s1);

print(s,n+1);











	return 0 ;
}






pair<int,long long> a[n];
bool cmp (pair<int,long long> a,pair<int,long long> b)
{
if(a.first>b.first || a.first<b.first)
  return a.first>b.first; 
else
  return a.second<b.second;

}


sort(a,a+n,cmp);