#include<bits/stdc++.h>
using namespace std;

std::string itob(int v) {
    std::string res;
    //dovode by 2 algo 
    while (v) {
        res += std::to_string(v % 2);
        v >>= 1;
    }
    std::reverse(res.begin(), res.end());
    return res;
}




int btoi(string s){
      int ans  = 0;
      int h =0;
      for(auto it = s.rbegin(); it != s.rend() ; ++it){
        ans+=((*it-'0')*(1<<h));
        h++;
      }
      return ans;

}


int main(){

  cout<<btoi(itob(357));


}