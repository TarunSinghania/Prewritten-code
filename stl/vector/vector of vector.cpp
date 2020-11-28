vector<vector<int> >   v2;
//note the space > > betweem


//grow with push back
vector<int> v(5);
v2.push_back(v);

//INTITALISED 

vector<int> v(5);
vector<vector<int> >   v2(8,v);

//or
vector<vector<int> >    v2(8, vector<int>(5));
//refering
v2[4][2] = 99;

//get iterator 
v2[0].begin();
v2[2].end();
vector<int>::iterator it = upper_bound(v2[0].begin(),v2[0].end(),32);

vector<int> t2 =  v2[0];



//loop
void display (const vector<vector<int> >& vy)
{  for (int i = 0; i < vy.size(); i++)       // loops through each row of vy
   {  for (int j = 0; j < vy[i].size(); j++) // loops through each element of each row 
          cout << " " << vy[i][j];           // prints the jth element of the ith row
      cout << endl;
   }
} 



//start code


#include <iostream>
#include <bits/stdc++.h>
using namespace std;


#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int

void display (const vector<vector<int> >& vy)
{  for (int i = 0; i < vy.size(); i++)       // loops through each row of vy
   {  for (int j = 0; j < vy[i].size(); j++) // loops through each element of each row 
          cout << " " << vy[i][j];           // prints the jth element of the ith row
      cout << endl;
   }
} 


int main() {

 
 
	int n;
	cin>>n;
	vector<vector<int> >   v2 ;
	
            for (int i = 0; i < n; i++) 
            {
                int k ;
                cin>>k;
                vector<int> v;
                
                    for (int j = 0; j < k; j++) 
                    {
                    
                    int temp;
                    cin>>temp;
                    v.push_back(temp);
         			
         			} 
                    
                    sort(v.begin(),v.end());            
                
                    v2.push_back(v);        
            }
            
  
	display(v2);
	return 0;
}





 sort(vect[0].begin(), vect[0].end()); 