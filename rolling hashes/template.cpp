#include <bits/stdc++.h>
using namespace std;
 
int MOD1 = 1000000007;
int MOD2 = MOD1 + 2;
vector<int>power1(1000000), power2(1000000);
 
int exp(int num, int p, int MOD) {
    int res = 1;
    while(p) {
        if(p&1) res = (1LL*res*num)%MOD;
        num = (1LL*num*num)%MOD;
        p>>=1;
    }
    return res;
}
int inv(int x, int MOD) {
    return exp(x, MOD-2, MOD);
}
 
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    power1[0] = power2[0] = 1;
    for(int i=1; i<1000000; i++) {
        power1[i] = (power1[i-1]*29LL)%MOD1;
        power2[i] = (power2[i-1]*31LL)%MOD2;
    }
    int inv1 = inv(29,MOD1);
    int inv2 = inv(31,MOD2);
    int n,q,x,h1,h2;
    cin>>n>>q;
    string s;
 
    set<pair<int,int>>arr;
    for(int i=0; i<n; i++) {
        cin>>x;
        cin>>s;
 
        h1 = h2 = 0;
        //inserting strings 
        for(int j=0; j<(int)s.size(); j++) {
            h1 = (h1 + 1LL*(s[j] - 'a'+1)*power1[j])%MOD1;
            h2 = (h2 + 1LL*(s[j] - 'a'+1)*power2[j])%MOD2;
        }
        arr.insert({h1,h2});
    }
    //test string 
    cin>>x;
    cin>>s;
    h1 = h2 = 0;
    for(int j=0; j<(int)s.size(); j++) {
        h1 = (h1 + 1LL*(s[j] - 'a'+1)*power1[j])%MOD1;
        h2 = (h2 + 1LL*(s[j] - 'a'+1)*power2[j])%MOD2;
    }
 
    char c;
    deque<char>str(s.begin(),s.end());
    while(q--) {
        cin>>x;
        if(x == 1) {
            cin>>c;
            //insert in begining
            h1 = (h1*29LL + (c-'a'+1))%MOD1;
            h2 = (h2*31LL + (c-'a'+1))%MOD2;
            str.push_front(c);
        }
        else if(x == 2) {
            cin>>c;
            h1 = (h1 + (c-'a'+1)*1LL*power1[str.size()])%MOD1;
            h2 = (h2 + (c-'a'+1)*1LL*power2[str.size()])%MOD2;
            str.push_back(c);
        }
        else if(x == 3) {
            //delete first character
            h1 = (h1 + MOD1 - (str.front()-'a'+1))%MOD1;
            h1 = (h1 *1LL*inv1)%MOD1;
 
            h2 = (h2 + MOD2 - (str.front()-'a'+1))%MOD2;
            h2 = (h2 *1LL*inv2)%MOD2;
 
            str.pop_front();
        }
        else if(x == 4) {
            //delete the last char
            h1 = (h1 + MOD1 - ((str.back()-'a'+1LL)*power1[str.size()-1])%MOD1)%MOD1;
            h2 = (h2 + MOD2 - ((str.back()-'a'+1LL)*power2[str.size()-1])%MOD2)%MOD2;
            str.pop_back();
        }
        else {
            if(arr.find({h1,h2}) == arr.end()) cout<<"no\n";
            else cout<<"yes\n";
        }       
    }   
}