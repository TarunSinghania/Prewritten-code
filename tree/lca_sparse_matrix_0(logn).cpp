#include <bits/stdc++.h>

using namespace std;
#define fr(i,a,b) for(int i =a ; i < b; i++)
#define pb push_back
#define mkp make_pair 
#define MAX 100005
#define MAX_LOG 25
#define INF 1000000
#define pr(a,b) fr(i,0,b){cout<<a[i]<<" ";}cout<<endl;
int v;
vector<int> adj[MAX];
int p[MAX][MAX_LOG+1],par[MAX],l[MAX];

void printsparpse()
{
     fr(i,1,v+1){
        int lim = log2(v+1);
        fr(j,0,MAX_LOG+1){
        cout<<p[i][j]<<" ";
        }
        cout<<endl;
    }
}

void parent(int n,int b,int le){
    par[n]=b;
    l[n]=le;
    for(auto x : adj[n])
        if(!par[x])
            parent(x,n,le+1);
}
 void preprocess(){
    parent(1,-1,0);
    fr(i,1,v+1)
        fr(j,1,MAX_LOG+1)
            p[i][j]=-1;
    fr(i,1,v+1){
        p[i][0]=par[i];
    }

    for(int j = 1; (1<<j) < v ; j++){
        for(int i = 1 ; i <= v ; i++){
            if(p[i][j-1] != -1){
                p[i][j] = p[p[i][j-1]][j-1] ; 
            }
        }
    }

} 

int lca(int u,int v)
{
    if(l[u]<l[v])
        swap(u,v);

    int d = l[u]-l[v];
    
    // while(d>0)
    // {
    //     int raise_by = log2(d);
    //     //ore use last set bit index -1
    //     u = p[u][raise_by];
    //     d-=(1<<raise_by);   
    // }
    // we are raising till height d
    for(int i = MAX_LOG; i >=0 ; i--)
    {   
        if(d>>i&1)
        {
            u  = p[u][i];
        }
    }
    if(u==v)
        return u;
    for(int j = MAX_LOG ; j >= 0 ; --j){ 
        if((p[u][j] != -1) and (p[u][j] != p[v][j])){
          //  cout<<"atj"<<j<<p[u][j]<<p[v][j]<<endl;
            u = p[u][j] ; 
            v = p[v][j] ; 
        }
    }
    //cout<<u<<endl;
    return par[u] ;

}



    
int main()
{
    cin>>v;
    fr(i,0,v-1)
    {   
        int x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    preprocess();
  //  printsparpse();
    cout<<lca(3,5);

}