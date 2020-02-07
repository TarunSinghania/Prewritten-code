#include<bits/stdc++.h>
using namespace std;
int main()
 {
	 int t;
	 cin>>t;
	 while(t--)
	 {
	    int n;
	    cin>>n;
	    
	    int a[n];
	    for(int i = 0 ; i < n ;i++)
	        cin>>a[i];
	    int dp1[n],dp2[n];
	    for(int i = 0 ; i < n ;i++){
	        dp1[i]=1;dp2[i]=1;
	    }
	     
	
	    //dp1 as larege dp2 as smal
	    for(int i =1 ; i < n ; i++)
        {
            for(int j = 0 ; j < i ; j++)
            {
                if(a[j]>a[i])
                dp2[i]= max(dp2[i],dp1[j]+1);
                
                if(a[i]>a[j])
                dp1[i]=max(dp1[i],dp2[j]+1);
            }
        }
        int ans = INT_MIN ; 
        for(int i = 0 ;i < n;i++)
        {
            ans = max(ans,max(dp1[i],dp2[i]));
        }
        
        cout<<ans<<endl;
	 }
	return 0;
}