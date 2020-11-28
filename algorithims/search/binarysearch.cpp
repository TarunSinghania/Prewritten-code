#include<bits/stdc++.h>
#define fr(i,a,b) for(int i = a ; i <b ; i++)
using namespace std;

void pr(int arr[],int r){
    for (int i = 0; i < r; i++) {
        cout<<arr[i];
    }
    cout<<endl;
}



int bn(int arr[], int l , int r , int f ){

	while(l<=r)
	{
		int m = l+ (r-l)/2;
		
		if(arr[m]== f)
			return m ;
		if(arr[m] > f)
			r = m-1 ;
		else
			l = m+1 ;
	}

	return - 1;
}

//bn index of  first element greater than f
int bng()(int arr[], int l , int r ,int f){

	int m = l + (r-l)/2;

	if(arr[m] <= f)
		l = m+1;
	//.....


}



int main ()
{

	int n ;
	cin>>n;
	
	int arr[n];
	fr(i,0,n)
	cin>>arr[i];

	sort(arr,arr+n);
	pr(arr,10);


	int r =bn(arr,0,n,8);//returns index of search element


	cout<<r<<endl;



	return 0 ;
}

