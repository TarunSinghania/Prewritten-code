    #include <iostream>
    #include <utility>
    #include <algorithm>
    #include <vector>
     
    using namespace std;
     
    bool comparison(const pair<int,int> &a,const pair<int,int> &b){
        return a.second<b.second;
    }
     
    int main() {
        // sorting a/c 2 first element beign here
        std::vector< pair<int, int> > vec;
        int n[] = {8, 1, 4, 3, 5, 2, 6, 7};
        int s[] = {1, 2, 3, 4, 5, 6, 7, 8};
        int l = sizeof(n)/sizeof(n[0]);
     
        for(int i=0; i<l;	i++){
         vec.push_back(make_pair(n[i], s[i]));
        }
     
        cout << "random vector" << endl;
        for(int i=0; i<l; i++){
    	    cout << vec[i].first << " " << vec[i].second << endl;
        }
     
        sort(vec.begin(), vec.end());
     
        cout << "sorted vector a/c to first " << endl;
     
        for(int i=0; i<l; i++){
    	    cout << vec[i].first << " " << vec[i].second << endl;
        }
        // sorting a/c 2 first element end here
     
        // sorting a/c 2 second element beign here
        std::vector< pair<int, int> > vec1;
        int n1[] = {8, 1, 4, 3, 5, 2, 6, 7};
        int s1[] = {1, 2, 3, 4, 5, 6, 7, 8};
        int l1 = sizeof(n)/sizeof(n[0]);
        
        for(int i=0; i<l1;	i++){
         vec1.push_back(make_pair(n1[i], s1[i]));
        }
        
        sort(vec1.begin(),vec1.end(), comparison);
        
        cout << "sorted vector a/c to second " << endl;
     
        for(int i=0; i<l1; i++){
    	    cout << vec1[i].first << " " << vec1[i].second << endl;
        }
        // sorting a/c 2 second element end here
        
        return 0;
    }