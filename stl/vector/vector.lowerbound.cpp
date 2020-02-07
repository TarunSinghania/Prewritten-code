#include<vector>
#include<iterator>


vector<int> v = {1,3,3,5,7};

auto it  = lower_bound( v.begin(),v.end(),3);
auto it2 = lower_bound(v.begin(),v.end(),4);
auto it3 = lower_bound(v.begin(),v.end(),8);
///lower bound equal to or greater 

cout<<(it != v.end()? to_string(*it) : "not found" ) <<endl ; //out[uts 3]
cout<<(it2 != v.end()? to_string(*it2) : "not found") <<endl ;//outputs 5 
cout<<(it3 != v.end() ?  to_string(*it3 : "not found") <<endl;  // outputs not found

//upperboung first element greater than 

upper_bound() the same would return 5 , 5 , not found 


custom function :

template <typename ForwardIterator, typename T>
ForwardIterator first_less_than (ForwardIterator first ,ForwardIterator last, T value)
{
	auto it = std::lower_bound (first,last,value);
	return (it == first ? last : --it);

}

vector<int> v = {1,3,3,5,7};

auto it  = first_less_than( v.begin(),v.end(),3);
auto it2 = first_less_than(v.begin(),v.end(),4);
auto it3 = first_less_than(v.begin(),v.end(),8);
///lower bound equal to or greater 

cout<<(it != v.end()? to_string(*it) : "not found" ) <<endl ; //out[uts 1]
cout<<(it2 != v.end()? to_string(*it2) : "not found") <<endl ;//outputs 3 
cout<<(it3 != v.end() ?  to_string(*it3) : "not found") <<endl;  // outputs 7

