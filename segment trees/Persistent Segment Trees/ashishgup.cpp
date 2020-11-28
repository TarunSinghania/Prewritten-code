#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5+5;
const int LG = log2(N) + 1;
 
int a[N];
int n, m, ct=0, num=0;
int root[N], st[21*N], li[21*N], ri[21*N];
map<int, int> comp;
map<int, int> rcomp;
 
int build(int L, int R)
{
	int nid = ++ct;
	if(L==R)
		return nid;
	int M = (L+R)/2;
	li[nid] = build(L, M);
	ri[nid] = build(M+1, R);
	return nid;
}
 
int update(int id, int L, int R, int pos)
{
	int nid = ++ct;
	if(L==R)
	{
		//adding one here for increasing count 
		st[nid] = st[id] + 1;
		return nid;
	}
	int M = (L+R)/2;
	li[nid] = li[id];
	ri[nid] = ri[id];

	if(pos <= M)
		li[nid] = update(li[id], L, M, pos);
	else
		ri[nid] = update(ri[id], M+1, R, pos);
	
	st[nid] = st[li[nid]] + st[ri[nid]];
	return nid;
} 
 
int query(int nodeu, int nodev, int L, int R, int pos)
{
	if(L==R)
		return L;
	int M = (L+R)/2;
	int leftval = st[li[nodev]] - st[li[nodeu]];
	int rightval = st[ri[nodev]] - st[ri[nodeu]];
	if(leftval>=pos)
		return query(li[nodeu], li[nodev], L, M, pos);
	else
		return query(ri[nodeu], ri[nodev], M+1, R, pos - leftval);
}
 
int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		comp[a[i]];
	}
	for(auto &it:comp)
	{
		it.second = ++num;
		rcomp[num] = it.first;
	}
	for(int i=1;i<=n;i++)
		a[i] = comp[a[i]];
	root[0] = build(1, num);
	for(int i=1;i<=n;i++)
		root[i] = update(root[i-1], 1, num, a[i]);


	cout<<st[root[0]]<<" "<<root[0]<<endl;
	cout<<st[root[1]]<<" "<<root[1]<<endl;
	cout<<st[root[2]]<<" "<<root[2]<<endl;
	cout<<st[root[3]]<<" "<<root[3]<<endl;
	cout<<st[root[4]]<<" "<<root[4]<<endl;
	cout<<st[root[5]]<<" "<<root[5]<<endl;


	for(int i=1;i<=m;i++)
	{
		int u, v, k;
		cin>>u>>v>>k;
		int store = query(root[u-1], root[v], 1, num, k);
		int val = rcomp[store];
		cout<<val<<endl;
	}
	return 0;
} 