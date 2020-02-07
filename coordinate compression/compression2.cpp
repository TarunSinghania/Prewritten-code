 int n;
    cin>>n;
    vector<int> v;
    fr(i,0,n)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    // check if numbers less than zero before using 
    v.pb(-1);
    sort(v.begin(),v.end());
    map<int,int> mp;
    int k = 1;
    fr(i,1,(int)v.size())
    {

        if(v[i] == v[i-1])continue;
        mp[v[i]]=k++;
    }