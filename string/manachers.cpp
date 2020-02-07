#include<bits/stdc++.h>
using namespace std;
string m(string &s)
{
    string k = "@";
    for(int i =0; i < s.length();i++)
    {
     k +="#"+s.substr(i,1);   
    }
    k+="#$";
    return k;
}

void lps(string k){
    string s = m(k);

    int c =0;int r =0;
    int p[s.size()]={0};
    for(int i = 1; i <(int)s.size()-1;i++)
    {
        
        int m = 2*c -i;
        if(r>i)
        {
            p[i]=min(r-i,p[m]);
        }
        while(s[i+p[i]+1] == s[i-p[i]-1])
            {
                p[i]++;
            }        
        if(i+p[i]>r)
        {
            c=i;
            r=i+p[i];
        }
    }
    
    int id=0;int mx =INT_MIN;

    for(int i = 0 ; i < (int)s.size() -1;i++)
    {
//      cout<<s[i]<<" ";
    }
   // cout<<endl;
    for(int i = 0 ; i < (int)s.size() -1;i++)
    {
  //    cout<<p[i]<<" ";
    }
    for(int i = 1; i <(int)s.size()-1;i++)
    {
        if(p[i]>mx)
        {
            mx = p[i];
            id = i;
        }
    }
    int ans = 0;
    //cout<<mx<<endl;
    //cout<<k.substr((id-mx-1)/2,mx);
    for(int i = 1; i < (int)s.size()-1;i++)
    {
        if(s[i]!='#')
        {
            ans+=ceil(1.0*p[i]/2);
        }
        else 
            ans+=p[i]/2;
    }
    cout<<ans<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--)
    {
    int k;
    cin>>k;
    string s;
    cin>>s;
    int x,y;
    cin>>x>>y;
    lps(s.substr(min(x,y),max(x,y)-min(x,y)+1));
    
    }
    return 0;
}