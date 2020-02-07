 by default first element is always the greatest of the elements(max heap)
normally ussing lesser comp
use greater <int> for larger comparator (min haep)


  
priority_queue <int> a;
------------------------------------------------------------------------------------------


This context is similar to a heap, where elements can be inserted at any moment, and only the max heap element can be retrieved (the one at the top in the priority queue).

lements are popped from the "back" of the specific container, which is known as the top of the priority queue.


    empty()
    size()
   
    push()
    pop()
    The standard container classes vector and deque fulfill these requirements. By default, if no container class is specified for a particular priority_queue class instantiation, the standard container vector is used.
------------------------------------------------------------------------------------
int myints[]= {10,60,50,20};

priority_queue<int> second (myints,myints+4);
priority_queue<int, vector<int>, greater<int> > third (myints,myints+4) ;
priority_queue <int, vector<int> , greater<int> > pq;


 std::cout << "mypq.top() is now " << mypq.top() << '\n';

     mypq.pop();

-----------------------------------------------------------------------------------------

Third has the same four ints, but because it uses greater instead of the default (which is less), it has 10 as its top element.

One container construction, and one call to make_heap, plus linear in the number of elements in the range [first,last) (if specified).


  

}//testcases
return 0 ;


}