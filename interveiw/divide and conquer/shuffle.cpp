#include <bits/stdc++.h> 
using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define speed   ios::sync_with_stdio(false), cin.tie(0) , cout.tie(0)
#define fillm(m,r,c,k) fr(i,0,r)fr(j,0,c)m[i][j]=k;
#define prm(m,r,c) fr(i,0,r){fr(j,0,c){cout<<m[i][j]<<" "; }cout<<endl;}
#define pr(a,n)fr(i,0,n)cout<<a[i]<<",";cout<<endl;
#define endl '\n'
#define MOD 1000000007
#define INF 1000000000
#define prv(v) for(auto x: v)cout<<x<<" ";cout<<endl;
#define MAX 100005
#define maxv 200005
#define all(x) x.begin(),x.end()
#define mkp make_pair 
#define ll long long
#define f first
#define s second
int a[MAX];
int n;
void leftRotate(int l,int r,int d) 
{ 
    /* To handle if d >= n */
    int n = r-l+1;
    int base = l;
    int g_c_d = __gcd(d, n); 
    for (int i = 0; i < g_c_d; i++) { 
        /* move i-th values of blocks */
        assert(i+base<MAX);
        int temp = a[i+base]; 
        int j = i; 
  
        while (1) { 
            int k = j + d; 
            if (k >= n) 
                k = k - n; 
  
            if (k == i) 
                break; 
  	   	   assert(j+base<MAX);
  	   	   assert(k+base<MAX); 
            a[j+base] = a[k+base]; 
            j = k; 
        } 
  	   	   assert(j+base<MAX);
        
        a[j+base] = temp; 
    } 
} 
void rightrotatebyk(int l,int r,int k){
	
	leftRotate(l,r,r-l+1-k);
}

void shuffle(int l,int r){
	if(r-l+1==2)
	{
		return;
	}
	int mid = (r+l)/2;
	int t = mid+1;
	int rcount =  r - mid;
	int toshift = rcount/2;
	rightrotatebyk(l+toshift,mid+toshift,toshift);
	shuffle(l,l+toshift+toshift-1);
	shuffle(l+toshift+toshift,r);
}

main(){
	speed;
	//a1 a2 a3 a4 b1 b2 b3 b4
	// a1 b1 a2 b2 a3 b3 a4 b4
		// n always even
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		fr(i,1,n+1){
			cin>>a[i];
		}
		shuffle(1,n);
		fr(i,1,n+1)
		cout<<a[i]<<" ";
		cout<<endl;
	}
}

