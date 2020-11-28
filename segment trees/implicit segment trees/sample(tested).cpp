//implicit segment tree
// dont use (l+r)/2 when l,r negative use (l+r)>>1
// (-5-4)/2 = -4 => l,m m+1,r  => -5,-4 -3,-4 
// (-5-4)>>1 = -5 => l,m m+1,r => -5,-5 -4,-4
#include<bits/stdc++.h>
using namespace std;
#define speed   ios::sync_with_stdio(false), cin.tie(0) , cout.tie(0)
#define fr(i,a,b) for(int i=a;i<b;i++)
#define ll long long
#define pb push_back
#define all(x) x.begin(),x.end()
#define f first
#define s second

class node{
public:
  ll val;
  struct node* l;
  struct node* r; 
  node(){
    val = 0;
    l = NULL;
    r = NULL;
  }
};
void upd(node* cur,ll l,ll r,ll id,ll v){
  if(l > id || r < id)
    return;
  if(l==r && l == id){
    cur->val += v;
    return;
  }
  ll m = (l + r)>>1;
  if(id <= m){
    if(cur->l==NULL)
      cur->l = new node();
    upd(cur->l,l,m,id,v);
  }
  else{
    if(cur->r == NULL)
      cur->r = new node();
    upd(cur->r,m+1,r,id,v);
  }
  ll s1 =0,s2 = 0;
  if(cur->l){
    s1 = cur->l->val;
  }
  if(cur->r){
    s2 = cur->r->val;
  }
  cur->val = s1 + s2;
}
ll qu(node* cur,ll l,ll r,ll ql,ll qr){
    if(!cur)
        return 0;

    if(l > qr  || r < ql)
        return 0;

    if(ql<=l && r <= qr){
      return cur->val;
    }
    ll m = (l + r)>>1;
    return qu(cur->l,l,m,ql,qr) + qu(cur->r,m+1,r,ql,qr);
}
class implicit_seg_tree{
public:
    node *root;
    ll maxl,maxr;
    implicit_seg_tree(ll l,ll r){
      root = new node();
      maxl = l;
      maxr = r;
    }
    void update(ll id,ll val){
      upd(root,maxl,maxr,id,val);
    }
    ll query(ll l,ll r){
      return qu(root,maxl,maxr,l,r);
    }
};


main(){
  speed;
  ll l = -1e9;
  ll r = 1e9;
  implicit_seg_tree st(l,r);
  st.update(5,4);
  cout<<st.query(1,6)<<endl;
} 
