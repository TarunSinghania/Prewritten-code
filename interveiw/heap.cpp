//pizza
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
#define MAX 400005
#define all(x) x.begin(),x.end()
#define mkp make_pair 
#define ll long long
#define f first
#define s second
class heap{
//max heap
public:
	int size;
	int cnt;
	int *key;
	int *val;

	heap(){
		size = 20;
		cnt = 0;
		key  = new int[size];
		val  = new int[size];
		for(int i = 0 ; i < size ; i++)
		{
			key[i] = -1;
			val[i] =  0;
		}
	}	
	heap(vector<pair<int,int> > v){
		size = max(size,2*(int)v.size());
		cnt = v.size();
		key  = new int[size];
		val  = new int[size];
		for(int i = 0 ; i < size ; i++)
		{
			key[i] = -1;
			val[i] =  0;
		}
		for(int i = 0 ; i < v.size() ; i++)
		{
			key[i+1]=v[i].f;
			val[i+1]=v[i].s;
		}
		for(int i= cnt/2; i>= 1; i--){
			down_heapify(i);
		}
	}
	~heap(){
		delete []key;
		delete []val;
	}
	int left(int id){
		if((id<<1) > cnt )
			return -1;
		return (id<<1);
	}
	int right(int id){
		if((id<<1) + 1 > cnt )
			return -1;
		return (id<<1) + 1;
	}

	void _swap(int p,int c){
		swap(key[p],key[c]);
		swap(val[p],val[c]);
	}
	bool valid(int p ,int c){
		if(key[p]>=key[c])
			return true;
		else
			return false;
	}
	int best(int p,int l,int r){
		if(valid(l,r)){
			//l is better than r
			if(valid(p,l))
				return p;
			else
				return l;
		}
		else{
			//r is better than l
			if(valid(p,r))
				return p;
			else
				return r;
		}
	}
	void resize(){
		size = size + size;
		int* tkey = new int[size];
		int* tval = new int[size];
		for(int i = 0 ; i < size ; i++)
		{
			tkey[i] = -1;
			tval[i] =  0;
		}
		for(int i = 1 ; i <= cnt ; i++)
		{
			tkey[i] = key[i];
			tval[i] = val[i];
		}
		delete []key;
		delete []val;
		key = tkey;
		val = tval;
	}
	void insert(int k,int v)
	{
		//1 indexing
		if(cnt == size - 1)resize();
		cnt = cnt  + 1;
		int id = cnt;
		key[id]=k;val[id]=v;
		while(id>1 && !valid(id>>1,id))
		{	
			_swap(id>>1,id);
			id = id>>1;
		}
	}
	void down_heapify(int id){
		int l = left(id);
		int r = right(id);
		if(l==-1 && r==-1)
			return;
		if(l==-1){
			if(valid(id,r))	
				return;
			else
			{swap(id,r),down_heapify(r);}
		}
		if(r==-1){
			if(valid(id,l))	
				return;
			else
			{swap(id,l),down_heapify(l);}
			return;
		}
		int newid = best(id,l,r);
		if(id==newid)return;
		_swap(id,newid);
		down_heapify(newid);
	}
	pair<int,int> pop(){
		if(cnt == 0)
			return {-1,-1};
		pair<int,int> t = {
			key[1],val[1]
		};

		_swap(1,cnt);
		cnt = cnt - 1;
		down_heapify(1);
		return t;
	}
};


main(){
	heap hp;
	hp.insert(2,1);
	hp.insert(3,2);
	hp.insert(5,3);
	hp.insert(10,4);
	hp.pop();
	hp.pop();
	vector<pair<int,int> > vv = {{2,1},{3,2},{5,3},{10,4},{11,5}};
	heap hp2(vv);
	cout<<hp2.key[1]<<endl;
	cout<<hp2.val[1]<<endl;

}
