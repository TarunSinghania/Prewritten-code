	vector<pair<int,LL>> v;
int main(){
  cin>>n;
  v.resize(n);
  for(int i=0; i<n; i++){
    cin>>v[i].second;
    v[i].first=-count3(v[i].second);
  }
  sort(v.begin(), v.end());
  for(int i=0; i<n; i++)
    printf("%lld%c", v[i].second, " \n"[i + 1 == n]);
}