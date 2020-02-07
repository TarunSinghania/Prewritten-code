int f(string a)
{

   int l = a.length();
        int dp[l][l];
        int isp[l][l];
        fillm(dp,l,l,0);
        fillm(isp,l,l,0);
        //checker if palindrome
        for(int i = l-1; i>=0; i-- )
        {
            frj(j,1,l)
            {
                if(i==j)
                isp[i][j]=1;
                else
                {
                    if(a[i]==a[j])
                        {
                            if(i+1>j-1)
                            isp[i][j]=1;
                            else
                            {
                                if(isp[i+1][j-1]==1)
                                isp[i][j]=1;
                            }
                            
                        }
                    
                }
            }
            
            
        }
        
        //dp solution 
        for(int i = l-1; i>=0; i-- )
        {
            frj(j,1,l)
            {
                if(isp[i][j]==1)
                    dp[i][j]=0;
                else{
                 
                 int k = j-i;
                    int l_min = INT_MAX;
                    
                    for(int h = 0 ; h < k ; h++)
                    {
                        
                        l_min = min(l_min,(dp[i][i+h]+dp[i+h+1][j]));
                       // cout<<i<<h<<j<<<<endl;
                        
                    }
                dp[i][j]=1+l_min;
                }
            }
            
        }
        //prm(dp,l,l);
        return dp[0][l-1];


}