multiset 
Multiple-key set
Multisets are containers that store elements following a specific order, and where multiple elements can have equivalent values.

In a multiset, the value of an element also identifies it (the value is itself the key, of type T). The value of the elements in a multiset cannot be modified once in the container (the elements are always const), but they can be inserted or removed from the container.

Internally, the elements in a multiset are always sorted following a specific strict weak ordering criterion indicated by its internal comparison object (of type Compare).

multiset containers are generally slower than unordered_multiset containers to access individual elements by their key, but they allow the direct iteration on subsets based on their order.

Multisets are typically implemented as binary search trees.


 // empty multiset container with descending orfer
    multiset <int, greater <int> > gquiz1;    

     // insert elements in random order
    gquiz1.insert(40);


    // printing multiset gquiz1
    multiset <int, greater <int> > :: iterator itr;
    cout << "\nThe multiset gquiz1 is : ";
    for (itr = gquiz1.begin(); itr != gquiz1.end(); ++itr)
    {
        cout << '\t' << *itr;
    }
    cout << endl;



     // assigning the elements from gquiz1 to gquiz2 in ascending ordef
    multiset <int> gquiz2(gquiz1.begin(), gquiz1.end());


      // remove all elements up to element with value 30 in gquiz2
    gquiz2.erase(gquiz2.begin(), gquiz2.find(30));


    *gquiz1.lower_bound(40);

    *gquiz2.upper_bound(40);

    
        multiset<int> :: iterator it ;
    
    cout<<s.size()<<" "; 

    for(it=s.begin();it!=s.end();++it)
        cout<<" "<< *it;
    cout<<endl;



