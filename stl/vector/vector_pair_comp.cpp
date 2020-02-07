//sort acc to primary index in ascending 
//if first value same then the other in desending 

bool cmp(const pair<int,int> &a,const pair<int,int> &b){
      if (a.first==b.first)
       return a.second>b.second;
      else
         return a.first <b.first;
    }


vector< pair <int ,int> > vv ;


for(auto &it : v)
{
  //cout<<it.first<<it.second<<endl;
  if(it.second == 's')
    cc++;
  else
    cc--;

  if(cc>m)
    m = cc;


}

co