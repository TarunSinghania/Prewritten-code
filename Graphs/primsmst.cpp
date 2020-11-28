
#define fr(i,a,b) for(int i =a ; i < b; i++)
#define mkp make_pair 
#define ll long long


void prims(int  v,std::vector< pair<int,int> > adj[]){

int start = 1;
int dist [v+1];
//bool vis [v+1];
int parent[v+1];int weights[v+1];
fr(i,0,v+1)
dist[i]=INT_MAX,weights[i]=0;


    dist[start] = 0; //from vertex one 
    set < pair < int , int > > s;       

    s.insert({0,start});               // insert the source node with distance = 0

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
                weights[e]=w;
                parent[e]=x;
                s.insert({dist[e],  e} );           // insert the next vertex with the updated distance
            }
        }//FOR

    }//while

//pr(dist,v+1,start);
ll minimumspanningtreeweight =0;
fr(i,1,v+1)
    minimumspanningtreeweight+=weights[i];
    
return minimumspanningtreeweight;


}