vector<int> lps(string s)
{
    int l = s.length();
    vector<int> ans(l,0);
    int len=0;
    for(int i = 1 ; i < l ; i++)
    {
        while(len!=0 && s[i]!=s[len])
        {
            len = ans[len-1];
        }
        if(s[i]==s[len])
        {
            len++;
            ans[i]=len;
        }
    }
    return ans;
}
 