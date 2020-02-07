void prints(stack<ll> &s)
{   vector<ll> tmp;
    while(!s.empty())
    {
    ll x= s.top();
    cout << x << "--";
    s.pop();
    tmp.push_back(x);          
    }
    cout << endl;
    reverse(all(tmp));
    for(auto x:tmp)
      s.push(x);
 }
