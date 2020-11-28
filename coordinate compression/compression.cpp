 int n;
    cin>>n;
    pair<int,int> p[n];
    vector<int> v;
    v.pb(-1);
    fr(i,0,n){
        cin >> p[i].first;
        cin >> p[i].second;
        v.pb(p[i].first);
        v.pb(p[i].second);
    }
    sort(v.begin(), v.end());
    map<int,int> mp;
    int k = 1;
    fr(i,1,(int)v.size())
    {
        if(v[i] == v[i-1])continue;
        mp[v[i]] = k++;
    }
    vector<pair<int,int> > vp;
    fr(i,0,n){
        vp.push_back(make_pair(mp[p[i].first],mp[p[i].second]));
    }   




   