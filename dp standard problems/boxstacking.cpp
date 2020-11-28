#include<bits/stdc++.h>
using namespace std;
int maxHeight(int height[],int width[],int length[],int n);
int main()
{
  int n;
  cin>>n;
  
  int A[1000],B[1000],C[10001];
  for(int i=0;i<n;i++)
  {
    int a,b,c;
    cin>>a>>b>>c;
    A[i]=a;
    B[i]=b;
    C[i]=c;
  }
  cout<<maxHeight(A,B,C,n)<<endl;
}


bool cmp(const pair<int,pair<int,int> > &a,const pair<int,pair<int,int> > &b){
    
      if (a.second.first*a.second.second==b.second.first*b.second.second)
       return a.first>b.first;
      else
         return a.second.first*a.second.second>b.second.first*b.second.second;

    
}


int maxHeight(int height[],int width[],int length[],int n)
{
    vector<pair<int,pair<int,int> > > b;
    for(int i =0;i<n;i++){
        b.push_back(make_pair(height[i],make_pair(width[i],length[i])));
        b.push_back(make_pair(height[i],make_pair(length[i],width[i])));
        b.push_back(make_pair(length[i],make_pair(height[i],width[i])));
        b.push_back(make_pair(length[i],make_pair(width[i],height[i])));
        b.push_back(make_pair(width[i],make_pair(height[i],length[i])));
        b.push_back(make_pair(width[i],make_pair(length[i],height[i])));
    }
    sort(b.begin(),b.end(),cmp);
    int lise[6*n] ={0};
    for(int i =0;i<6*n;i++)
        lise[i]=0;
    lise[0]=b[0].first;
    int mx = 1;
    for(int i = 1 ; i < 6*n;i++)
    {   mx =0;
        for(int j =0;j<i;j++)
        {
           if(b[j].second.first>b[i].second.first && b[j].second.second>b[i].second.second)
                mx = max(mx,lise[j]);
        }    
        lise[i] = mx + b[i].first;
    }
    
    for(int i =0;i<6*n;i++)
    {
        mx = max(lise[i],mx);
    }
    return mx;
}