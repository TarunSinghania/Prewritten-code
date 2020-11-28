#include <iostream>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;

using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, 
             tree_order_statistics_node_update> ordered_multiset;

int main() {
	ordered_multiset ms;
    vector<int> v{1, 1, 2, 2, 3, 4, 5, 6, 6};

    for(int i : v) ms.insert(i);

	cout << "Ordered Multiset: ";
    for(auto x : ms) cout << x << ' '; cout << '\n';

    cout << "Lower bound of 2: " << *ms.lower_bound(2) << '\n';
    cout << "Upper bound of 2: " << *ms.upper_bound(2) << '\n';
    return 0;
}

//will work in codeforces
//Another drawback of using less_equal 
//instead of less is that lower_bound works as upper_bound and vice-versa
use cant use erase then  too
Note on using less_equal as comparison function to use it as a multiset:

_GLIBCXX_DEBUG must not be defined, otherwise some internal check will fail.
find will always return end.
lower_bound works like upper_bound in normal set (to return the first element > it)
upper_bound works like lower_bound in normal set (to return the first element >= it)
find_by_order and order_of_key works properly (unlike the 2 functions above).