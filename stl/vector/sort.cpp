    vector<int> v;
    fr(i,1,n+1){
    v.pb(i);
	}
	fr(i,1,n+1)
    {
      cin>>topic[i];
    }
  // sort indices according to their number of topiss;
 sort(all(v),[&](int i, int j){return topic[i] < topic[j];});
