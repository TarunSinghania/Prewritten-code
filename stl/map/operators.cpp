lower bound ==

equal or greater 

logn time



 std::map<char,int> mymap;
  std::map<char,int>::iterator it;

  mymap['a']=50;
  mymap['b']=100;
  mymap['c']=150;
  mymap['d']=200;

  it = mymap.find('b');
  if (it != mymap.end())
    mymap.erase (it);




std::map<char,int> anothermap;
  anothermap.insert(mymap.begin(),mymap.find('c'));




   std::cout << "mymap contains:\n";
  for (it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';



References and iterators to the erased elements are invalidated. Other references and iterators are not affected.

The iterator pos must be valid and dereferenceable. Thus the end() iterator (which is valid, but is not dereferencable) cannot be used as a value for pos.






Erasing an element of a map invalidates iterators pointing to that element (after all that element has been deleted). You shouldn't reuse that iterator.

Since C++11 erase() returns a new iterator pointing to the next element, which can be used to continue iterating:

it = mymap.begin();
while (it != mymap.end()) {
   if (something)
      it = mymap.erase(it);
   else
      it++;
}




	