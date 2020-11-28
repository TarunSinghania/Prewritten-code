    #include <iostream>
    #include <vector>
     
    void function(std::vector<int> *array)
    {
      	std::cout << "Passed\n";
    }


    //or

void ae(vector<int> v[] , int x ,int y){

  v[x].push_back(y);

}


    int main()
    {
     	std::vector<int> array[10];
     	function(array);
      ae(array,19,2);
    }