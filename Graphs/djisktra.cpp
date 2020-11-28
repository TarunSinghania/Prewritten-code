  #include <bits/stdc++.h>

using namespace std;
#define ll long long
#define fr(i,a,b) for(int i =a ; i < b; i++)
#define fre(i,a,b) for(int i =a ; i <= b; i++)
#define fra(s) for(auto it = s.begin(); it != s.end() ; ++it)

#define mkp make_pair 
#define pb push_back
#define pii pair<int,int>
#define speed   ios::sync_with_stdio(false), cin.tie(0) , cout.tie(0)
#define c(a,b) cout<<a<<"--"<<b<<endl;
#define frv(i,a,v) for(int i =  a ; i < v.size() ; ++i)
#define cp(a,i)  cout<<a[i].first<<" "<<a[i].second<<endl;
#define mp(a) cout<<a->first<<" "<<a->second<<endl;
//sum array
#define sa(n) int a[n]; int s[n];cin>>a[0];s[0]=a[0];fr(i,1,n) {cin>>a[i];s[i]=s[i-1]+a[i];}
#define sa1(n) int a[n+1]; long long s[n+1]; a[0]=0; s[0]=0;cin>>a[1];s[1]=a[1];fr(i,2,n+1) {cin>>a[i];\
s[i]=s[i-1]+a[i];}


#define MOD 1000000007


void ae(vector<int> v[] , int x ,int y){

  v[x].push_back(y);

}


void prw(vector<pair<int,int> > v [], int ttv)
{

fr(i,1,ttv+1)

{
  cout<<"i--";
  for(auto it = v[i].begin(); it != v[i].end(); ++it)
  cout<<it->first<<" "<<it->second<<"--"<<endl;
}

}
//unidirected 
//addedge
//veector array passed as refernce by default use structure wrapper for by value
void ae(vector<pair<int,int> > v[] , int x ,int y ,int w){

  v[x].push_back(mkp(y,w));
  v[y].pb(mkp(x,w));

}
void pr(int arr[],int r,int ex){
    for (int i = 1; i < r; i++) {
        if(i!=ex)
          if(arr[i]!=INT_MAX)
            cout<<arr[i]<<" ";
          else
            cout<<"-1"<<" ";
    } 
    cout<<endl;
}




void dijkstra(int  v,std::vector< pair<int,int> > adj[],int start ){

int dist [v+1];
//bool vis [v+1];
fr(i,0,v+1)
dist[i]=INT_MAX;

    dist[start] = 0; //from vertex one 
    set < pair < int , int > > s;       

    s.insert({0 , start});               // insert the source node with distance = 0

    while(!s.empty()){

      //not sure 2*Vlogv + descrease key(ElogV find +ElogV erase + E logV insert)
      //VLOGV + 3ElogV
        pair <int , int> p = *s.begin();        // pop the vertex with the minimum distance
        s.erase(s.begin());

        int x = p.second; int wei = p.first;
     
    for(int i = 0; i < adj[x].size(); i++){
            int e = adj[x][i].first; int w = adj[x][i].second;
           //cout<<e<<"e"<<dist[e]<<endl;
            if(dist[x] + w < dist[e]  )
            {            // check if the next vertex distance could be minimized
                

                if(dist[e] != INT_MAX)
                s.erase(s.find(mkp(dist[e],e)));
                
                dist[e] = dist[x] + w;
                s.insert({dist[e],  e} );           // insert the next vertex with the updated distance
            }
        }//FOR

    }//while

pr(dist,v+1,start);

}




int main()
{
  speed;
  int t ;
  cin>>t;
  while(t--)
  {
  int v,edges;
  cin>>v>>edges;

  //linked list 
  vector<pair<int,int> > adj[v+1];

int a ,b,w;
  fr(i,0,edges){
  cin>>a>>b>>w;
  ae(adj,a,b,w);
}
//prw(adj,v);

  int s ;
 cin>>s;
  dijkstra(v,adj,s);



}

return 0 ;


}   