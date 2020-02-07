    #include <bits/stdc++.h>

    #include<ext/pb_ds/assoc_container.hpp>
    #include<ext/pb_ds/tree_policy.hpp>
    #define INF 1e6
    using namespace std;

    using namespace __gnu_pbds;
    typedef tree<
    pair<int, int>,
    null_type,
    less<pair<int, int>>,
    rb_tree_tag,
    tree_order_statistics_node_update> ordered_multiset;


    int main() {
        ordered_multiset ms;
        vector<int> v{1, 1,3, 4, 5, 6, 6,7};
        unordered_map<int,vector<int> > mp;
        
        for(int i = 0 ; i < v.size() ; i++){
        ms.insert(make_pair(v[i],i));
        mp[v[i]].push_back(i);
        }    
        cout << "Ordered Multiset: ";
        
        for(auto x : ms) cout << x.first <<','<<x.second<<" "; cout << '\n';
        ms.erase(make_pair(1,1));
        for(auto x : ms) cout << x.first <<','<<x.second<<" "; cout << '\n';
        //finding lower bound of a number expample 6
        cout << "Lower bound of 2: " << ms.lower_bound(make_pair(6,-1))->first<<" "<<ms.lower_bound(make_pair(6,-1))->second<<'\n';
        cout << "Upper bound of 2: " << ms.upper_bound(make_pair(6,INF))->first<<" "<<ms.lower_bound(make_pair(6,INF))->second<<'\n';
        cout << ms.find_by_order(1)->first ;
        cout << ms.order_of_key(make_pair(1,0)) ;

//The first returns an iterator to the k-th largest element
// (counting from zero), the second — the number of items in a set 
//that are strictly smaller than our item
        return 0;
    }
