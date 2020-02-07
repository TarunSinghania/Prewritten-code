pair<string,ll> longdiv(string dd, ll dv){

    string ans;
    ll idx = 0;
    ll temp = dd[idx]-'0';
    while(temp<dv && idx+1<(ll)dd.size())
    { 
        temp = (temp*10) + (dd[++idx]-'0');
    }
    while((ll)dd.size() >idx)
    {

        ans+=temp/dv + '0';
        temp = (temp%dv);
        ++idx;
        if(idx<(ll)dd.size()) 
        temp =temp*10+ dd[idx]-'0';        
    }

    return mkp(ans,temp);
}
