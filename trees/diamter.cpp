Algorithm to find diameter of a tree is :-

1) Choose random node s and find farthest node u from s.

2) Find farthest node v from u.

3) d(u,v) is the diameter.


proof : 
step 1: 
2 cases : random node on diamter or not on diameter
 if on diamter then the farthest node will be a diamter node.
 	(draw tree you will know why)
 	else 
random node not on diamter
	then proof by contracdiction 

	https://www.youtube.com/watch?v=2PFl93WM_ao


pair<int,int> farthest(int node){
  bool vis[n+1];
  fr(i,0,n+1)
    vis[i]=false;
  queue<pair<int,int> > q;
  q.push(mkp(node,0));
  vis[node]=true;
  pair<int,int> ans = mkp(node,0);
  while(!q.empty()){
    int c = q.front().first;
    int d = q.front().second;
    for(auto x : adj[c]){
      if(!vis[x])
      {
        vis[x]=true;
        q.push(mkp(x,d+1));
      }
    }
    if(d > ans.second)
    {
      ans.first = c;
      ans.second = d;
    }
    q.pop();
  }
  return ans;
}


int diameter(int node){
  //returns length of diameter
 int leaf =  farthest(node).first;
 return farthest(leaf).second;
}
