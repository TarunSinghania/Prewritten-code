void setkthbit(ll &n,ll k){
    //indexong from 1st bit
      n=   1<<(k-1)|n;

}

void unsetkthbit(ll &n,ll k){
    //indexong from 1st bit
        n = 0<<(k-1)|n;
}

ll xnor(ll a,ll b){
    //upto 60 bits implementation
    int dp[65]={0};
    int dp2[65]={0};
    fr(i,1,62){
        dp[i]=a&1;
        a=a>>1;
        dp2[i]=b&1;
        b=b>>1;
    }
    ll ans = 0;
    bool seen = false;

    for(int j = 60; j >0; j--)
    {
        if(dp[j]==1 || dp2[j]==1)
            seen = true;
        
        if(seen){
            if(dp[j]==0 && dp2[j]==0)
                setkthbit(ans,j);
            if(dp[j]==1 && dp2[j]==1)
                setkthbit(ans,j);
            if(dp[j]==0 && dp2[j]==1)
                unsetkthbit(ans,j);
            if(dp[j]==1 && dp2[j]==0)
                unsetkthbit(ans,j);
        }
    }
    return ans;
}
