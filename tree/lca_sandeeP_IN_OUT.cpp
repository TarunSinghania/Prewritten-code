#include <bits/stdc++.h>
using namespace std;
 
#define speed ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ub(a,x) upper_bound(a.begin(),a.end(),x)-a.begin()
#define lb(a,x) lower_bound(a.begin(),a.end(),x)-a.begin()
#define ll long long
#define endl "\n";
#define all(v) v.begin(),v.end()
#define ff first
#define ss second
#define pb push_back
#define PI 3.1415926535897932384626
 
const int M = 1005,l=12;
vector<int> v[M];
int up[M][l],in[M],out[M],time_,n;
bool vis[M];
 
void dfs(int u,int p)
{
    in[u] = ++time_;
    up[u][0] = p;
    vis[u] = true;
    for(int i=1;i<l;i++)
    {
        up[u][i] = up[up[u][i-1]][i-1];
    }
    for(int i=0;i<v[u].size();i++)
    {
        if(!vis[v[u][i]])
        {
            dfs(v[u][i],u);
        }
    }
    out[u] = ++time_;
}
 
bool is_ancestor(int x,int y)
{
    return in[x]<=in[y] && out[x]>=out[y];
}
 
int lca(int x,int y)
{
    if(is_ancestor(x,y))
    {
        return x;
    }
    if(is_ancestor(y,x))
    {
        return y;
    }
    for (int i = l-1; i >= 0; --i) 
    {
            if (!is_ancestor(up[x][i], y))
            {
                x = up[x][i];
            }
        }
      return up[x][0];
}
 
main()
{
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			v[i].clear();
		}
		for(int j=1;j<=n;j++)
		{
			int x;
			cin>>x;
			for(int k=0;k<x;k++)
			{
				int y;
				cin>>y;
				v[j].pb(y);
				v[y].pb(j);
			}
		}
		memset(in,0,sizeof(in));
		memset(out,0,sizeof(out));
		memset(up,0,sizeof(up));
		memset(vis,false,sizeof(vis));
		time_ = 0;
		dfs(1,1);
		int q;
		cin>>q;
		cout<<"Case "<<i<<":\n";
		while(q--)
		{
			int x,y;
			cin>>x>>y;
			cout<<lca(x,y)<<"\n";
		}
	}
}