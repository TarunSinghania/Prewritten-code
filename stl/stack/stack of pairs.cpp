
#include<bits/stdc++.h>

using namespace std;
//will effect copy of stack orignial already there 
void psp(stack< pair<int,int> > stack) {

    while(!stack.empty())
    {
        cout<<stack.top().first<<" " <<stack.top().second<<" " ;
        stack.pop();

    }
    cout<<endl;
}

int main( )
{
    int num_loads = 5;
    int palettes[num_loads] = { 7, 6, 2, 5, 10 };
    string destinations[num_loads] = { "A", "B","C", "D", "E" };

   // load up the truck
   stack< pair<int,string> > truck;
   cout << "LOADING TRUCK";
   for( int i = 0; i < num_loads; ++i )
   {
      truck.push( make_pair( palettes[i], destinations[i] ) );
      cout << "\nLoaded " << truck.top().first << " palettes for " << truck.top().second;
   }

   // make the trip
   cout << "\n\nTRUCK EN ROUTE";
   while( !truck.empty() )
   {
      cout << "\nDelivered " << truck.top().first << " palettes to " << truck.top().second;
      truck.pop();
   }
}
