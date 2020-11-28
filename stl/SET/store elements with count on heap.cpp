store elements with count on heap 

heap each node with count 
while delete in heap if count == 0 then dlete or else coun-1;

but if you search in heap its otime complexity is high 



You need to search through every element in the heap in order to determine if an element is inside.

One optimization is possible, though (we assume a max heap here). If you have reached a node with a lower value than the element you are searching for, you don't need to search further from that node. However, even with this optimization, search is still O(N) (need to check N/2 nodes in average).

heap delete will also consume 0(logn)
delted element replaced by maximum avilable element and then heap is fixed ;



instead of heap use sets :

binary search tress
search log(n) update log(n)
miin (1) max(1)

use with it hash map to see count 

if(!myset.empty())
    *myset.rbegin();
else
	//this set is empty





Return iterator to end
Returns an iterator referring to the past-the-end element in the set container.

The past-the-end element is the theoretical element that would follow the last element in the set container. It does not point to any element, and thus shall not be dereferenced.

Because the ranges used by functions of the standard library do not include the element pointed by their closing iterator, this function is often used in combination with set::begin to specify a range including all the elements in the container.

If the container is empty, this function returns the same as set::begin.



max element 0(1);
min element begin iterator o(1);

store count of elements in hash map 
