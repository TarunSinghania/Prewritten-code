 vector<stack<int> > adj(v+1);
     vector<queue<int> > adj2(v+1);

      fr(i,0,e-1)
     {
        cin>>a>>b;
        adj[a].push(b);
      //  ae(adj,a,b);
     }
     
     fr(i,0,e-1)
     {
      cin>>a>>b;
        adj2[a].push(b);
     // ae2(adj2,a,b);
     }