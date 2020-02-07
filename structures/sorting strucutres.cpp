#include<bits/stdc++.h>
#define fr(i,a,b) for(int i = a ; i<b; i++)
using namespace std ;
struct demo {

  int a , b ,c ;
};

bool c(demo d1, demo d2 ){

if(d1.a!=d2.a)
  return d1.a<d2.a;
else if( d1.b!=d2.b)
  return (d1.b<d2.b);
else
  return(d1.c<d2.c);
}

void p (demo a[],int s){

  fr(i,0,s)
  cout<<a[i].a<<a[i].b<<a[i].c<<endl;
}

int main(){
  

  demo arr[] ={{1,3,3,},{1,2,4},{1,2,5},{1,5,4}};

  int n = sizeof(arr) / sizeof(arr[0]);

  stable_sort(arr,arr+n,c);

  p(arr,n);


}