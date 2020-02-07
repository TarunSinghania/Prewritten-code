#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void rightrotate(int a[],int n)
{   int end ;
    end=a[n-1];
    for (int i =n-2; i >=0 ; i--) {
        a[i+1]=a[i];
    }
    a[0]=end;
}

void leftrotate(int arr[],int start , int end )
{
    while(start+1<end){
        arr[start]=arr[start+1];
        start++;
    }
}
void deletearr(int arr[],int n, int size )
{
    int last = size -n + 1;
    int  index = size -last ;
    if(index>=0)
    {
        arr[index] = 0;
        leftrotate(arr,index,n);
    }
    else
    {
        arr[0] = 0 ;
        //leftrotate(arr,0,n);
    }
}
void pr(int arr[],int r){
    for (int i = 0; i < r; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


int findindex(int arr[], int r ,int a){
    
        for (int i = 0; i < r; i++) {
        if ( arr[i] == a )
        return i ;
        
    }
    return -1 ;
}

void copyarray (int arr[],int arrnew[],int n ){
    
    for (int i = 0; i < n; i++) {
        /* code */
        arrnew[i]=arr[i];
    }
    
}




int main() {

 
 
	int r;
	cin>>r;
	int size = r ;
	int arr[r];
            for (int i = 0; i < r; i++) {
                                            
                        cin>>arr[i];
                        }

    sort(arr,arr+r);

    cout<<endl;
 
 
 
 
 //size_t NumberOfElements = sizeof(arr)/sizeof(arr[0]);


	return 0;
}
