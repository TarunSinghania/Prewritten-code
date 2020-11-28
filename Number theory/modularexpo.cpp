
ll me(ll x,ll n)
{
  x = x% MOD;//SAFTETY

  ll r=1;
  while(n>0)
  {
  if(n % 2 ==1)
  r=(r * x)%MOD;
  x=(x*x)%MOD;
  n=n/2;
}
return r ;

}

//if you subtract (me(5,10) - me(5,12) +MOD )%MOD
//matrix 
  void ml(ll a[3][3] , ll b[3][3])
  {
    ll mm[3][3] ;
    fr(i,0,3)
      frj(j,0,3)
          {
            mm[i][j] = 0 ;
              frk(k,0,3)
                mm[i][j]+= (a[i][k] * b[k][j]) %MOD;
         }


        fr(i,0,3)
          frj(j,0,3)
            a[i][j] = mm[i][j];
     
        
     
  }

  void pow( ll a[3][3] , int n)
  {
    ll r[3][3]={{1,0,0},{0,1,0},{0,0,1}};

    while(n>0){
      if(n%2 == 1)
          ml(r,a);
      ml(a,a);
      n=n/2;
    }

    fr(i,0,3)
      frj(j,0,3)
        a[i][j] = r[i][j];
        
      
    
    
  }

  
pow(a,n);