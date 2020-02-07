double m3(double a , double b , double c){
  return max(a,max(b,c));
}


int main()
{
    int a = 1;
    int b = 2;
    int c = 3;

    int m = std::max({a, b, c});

    std::cout << m << "\n";
}


int res = *max_element( intList.begin(),  intList.end() ); //where intList is the list



cout<<*min_element(a,a+n)<<endl;