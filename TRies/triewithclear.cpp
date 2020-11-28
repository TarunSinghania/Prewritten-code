//making a effcient trie template
//https://codeforces.com/problemset/problem/923/C
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

struct node{
  int end;
  int sm;
  map<char,node*> child;
  node(){
    sm =  0;
    end = 0;
    child.clear();
  }
};

class trie{
public:
  node* root;
  trie(){
    root = new node();
  }
  void insert(vector<char> v){
    node* temp = root;
    fr(i,0,v.size()){
    if(temp->child[v[i]]==NULL)
        temp->child[v[i]]=new node();
         temp->sm+=1;
      temp = temp->child[v[i]];
    }
    temp->sm+=1;
    temp->end+=1;
  }
  void remove(vector<char> v){
    node* temp = root;
    //stack to store ex xD
    stack<node*> st;
    fr(i,0,v.size()){
      temp->sm -=1;
      st.push(temp);
      temp = temp->child[v[i]];
    }
    temp->sm-=1;
    temp->end-=1;
    int id = v.size()-1;
    while(!st.empty()){
      //revisiting ex
      node* ex = st.top();
      st.pop();
      if((ex->child[v[id]])->sm==0)
      {
        free(ex->child[v[id]]);
        ex->child[v[id]]=NULL;
      }
      id--;
    }
  }
  int domagic(vector<char> v){
    int ans = 0;
    node* temp = root;
    fr(i,0,v.size()){
      if(temp->child[v[i]^1]!=NULL){
        temp = temp->child[v[i]^1];
        ans = ans + (1<<(29-i));
      }
      else if(temp->child[v[i]]!=NULL){
        temp = temp->child[v[i]];
      }
    }
    return ans;
  }
};

main(){
  int n;
  cin>>n;
  trie tr;
  vector<char> bit(30,'0');
  tr.insert(bit);
  fr(i,0,n){
    char a;
    int x;
    cin>>a>>x;
    vector<char> bit(30,'1');
    for(int i = 29 ; i >= 0 ; i--)
    {
        bit[29-i]=((x&(1<<i))!=0?'1':'0');
    }
    if(a=='+'){   
      tr.insert(bit);
    }
    else if(a=='-'){
      tr.remove(bit);
    }
    else{
      cout<<tr.domagic(bit)<<endl;
    }
  } 
}