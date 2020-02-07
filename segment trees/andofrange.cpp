void b(int n , int s , int e)
{   
    if(s==e)
        t[n]=a[s];
    else
        {   int m = (s+e)>>1;
            b(2*n,s,m);
            b(2*n+1,m+1,e);
 
            t[n]= t[2*n]&t[2*n+1];
        }   
}
 
int q(int n,int s,int e, int l, int r)
{
   // cout<<"--"<<l<<"---"<<r<<endl;
    if(r<s || l >e)
        return INT_MAX;
 
    if(l<=s && e<=r)
        return(t[n]);
 
    int m = (s+e)>>1;
 
    int p1 = q(2*n,s,m,l,r);
    int p2 = q(2*n+1,m+1,e,l,r);
  // cout<< p1<<p2<<"p"<<endl;
    return p1&p2 ;
}
 
 b(1,0,n-1);
 q(1,0,n-1,lll,rrr);