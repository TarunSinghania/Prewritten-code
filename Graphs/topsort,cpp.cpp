vector<int> topoSort(int V, vector<int> adj[])
{
    int in[V]={0};
    fr(i,0,V)
    {
        for(auto x:adj[i])
            in[x]++;
    }
    queue<int> q;
    fr(i,0,V)
    if(in[i]==0)q.push(i);
    int c =0;
    vector<int> ans;
    while(!q.empty())
    {
        int k = q.front();
//        cout<<k<<endl;
        q.pop();
        ans.pb(k);
        for(auto x: adj[k])
            if(--in[x] == 0 )
                q.push(x);
        c++;
    }
    if(c!=V)
    cout<<"not a dag"<<c<<endl;
    return ans;
}