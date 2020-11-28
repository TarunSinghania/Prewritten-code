 std::unordered_map<std::string,std::string> mymap;

  mymap["Bakery"]="Barbara";  // new element inserted
  mymap["Seafood"]="Lisa";    // new element inserted
  mymap["Produce"]="John";    // new element inserted

  std::string name = mymap["Bakery"];   // existing element accessed (read)
  mymap["Seafood"] = name;              // existing element accessed (written)

  mymap["Bakery"] = mymap["Produce"];   // existing elements accessed (read/written)

  name = mymap["Deli"];      // non-existing element: new element "Deli" inserted!

  mymap["Produce"] = mymap["Gifts"];    // new element "Gifts" inserted, "Produce" written


 What is unordred_map?

It is a data structure like map but it is more than 4 times faster than map.you can use it in C++11 with including #include<unordered_map>.for example:

#include<unordered_map>
using namespace std;
int main(){
  unordered_map<int,int>mp;
  mp[5]=12;
  mp[4]=14;
  cout<<mp[5]<<' '<<mp[4]<<endl;//prints: 12 14
}

Lets explain it more.
How it works?

Focus on unordered_set for simplify.You can imagine that it has vector of vector like 
		vector< vector<type> > mp.
Every time you insert value V in that, it calculate its hash(I will explain how it works), let hash(V)=K; 

it inserts V into mp[K] (formally it calls mp[K].push_back(V)).When you call mp.count(V) it searchs for V 
in mp[K].
















  