#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(int i =a ; i < b; i++)
#define ll long long
#define speed   ios::sync_with_stdio(false), cin.tie(0) , cout.tie(0)
#define all(v) v.begin(), v.end()
#define prv(v)   for(auto it = v.begin() ; it!= v.end() ;++it){cout<<*it<<" ";}cout<<endl;

const int maxn = 1e5+10;

vector<int> tree[4*maxn];
int n, m, arr[maxn]; 

void build(int node, int l, int r) {
  
  if(l == r) {
    tree[node].push_back(arr[l]);
    return;
  } 
  //l and r less than 1e5 so no overflow
  int m = l+(r-l)/2;
  
  build(2*node,l,m);
  build(2*node+1,m+1,r);
  
  merge(all(tree[2*node]), all(tree[2*node+1]), 
          back_inserter(tree[node]));
  //cout<<node<<"#"<<endl;
  //prv(tree[node]);
}

int q1(int node, int l, int r, int i, int j, int k) {
  //elements less than k 
  if(i > r || l > j) return 0;
  if(i <= l && r <= j) {
    return lower_bound(all(tree[node]), k)- tree[node].begin();
  } 
  int m = l+(r-l)/2;
  return q1(2*node, l, m, i, j, k) + 
       q1(2*node+1, m+1, r, i, j, k);
}
int q2(int node, int l, int r, int i, int j, int k) {
  //elements less than equal to  k 
  if(i > r || l > j) return 0;
  if(i <= l && r <= j) {
    return upper_bound(all(tree[node]), k)- tree[node].begin();
  } 
  int m = l+(r-l)/2;

  return q2(2*node, l, m, i, j, k) + 
       q2(2*node+1, m+1, r, i, j, k);
}

int q3




main()
{
    cin>>n>>m;
    fr(i,0,n){
        cin>>arr[i];
        //cout<<arr[i]<<endl;
        }

    build(1,0,n-1);
    fr(i,0,m)
    {

        int l,r,k;
        cin>>l>>r>>k;
        cout<<l<<r<<k<<endl;
        cout<<q1(1,0,n-1,l-1,r-1,k)<<endl;

    }
}