    #include <bits/stdc++.h>

    using namespace std;
    #define ll long long


    vector<int> alldivisors(ll n)
    {   
        vector<int> b;
         for(ll i = 2 ; i*i <= n; i++)
        {   
            if(n%i == 0){

              if(n/i == i)
                 b.push_back(i);
              else
                 b.push_back(i),b.push_back(n/i);
            }
        }
        return b;
    } 


int main()
{
      ll t;
      cin>>t;
      vector<int> divisors = alldivisors(t);
      for(auto it =divisors.begin(); it!= divisors.end(); ++it)
          cout<<*it<<endl;
      return 0;
} 
      
    