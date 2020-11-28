maps are used to replicate associative arrays

//numeric arrays index represented by numbers  .
 
 maps contains	sorted key value pair 	in which each key is unique and cannot be chaged ,and it can be inserted or deleted but cannot be altered .


 soerted in dictionary order . key values 	


map, set, multimap, and multiset

These are implemented using a red-black tree, a type of balanced binary search tree. They have the following asymptotic run times:

Insertion: O(log n)
Lookup: O(log n)
Deletion: O(log n)

hash_map, hash_set, hash_multimap, and hash_multiset

These are implemented using hash tables. They have the following runtimes:

Insertion: O(1) expected, O(n) worst case
Lookup: O(1) expected, O(n) worst case
Deletion: O(1) expected, O(n) worst case







 #include<map>
 using namespace std ;

 int main ( ){


map<int,string> customer ;

customer[100]="Gajju";


map <int,string> custom { {171,"gajju"} ,{12,"nunu"}} ;


cout<<customer[100]<<endl;

map<int,string>::iterator p = customer.begin();

while(p!=customer.end())
{
cout<<p->second<<endl;
p++;
}



 	return 0 ;
 }

 auto it = m.begin();
		//cout<<"yo00"<<endl;
		
		int c = 0 ; 
		while(it!= m.end())
		{
			if(it->first == 0 || it->first == 1)
			{it++;	continue;}


			//c++;

			if(c>1)
			break;

			it++;
		}

		if(c<=1)
		cout<<"yes"<<endl;
		else
		cout<<"no"<<endl;	
