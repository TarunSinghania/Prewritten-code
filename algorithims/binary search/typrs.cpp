
	int l =i ; int r = n;
	
	while(l<r)
	{
		int m = l+(r-l+1)/2;
		if(confition)
			l = m;
		else
			r = m-1;
	}
 	
 	ans = l;

 //	type 2 
//
	int l =i ; int r = n;
	
while(l<r)
	{
		int m = l+(r-l)/2;
		if(confition)
			l = m+1;
		else
			r = m;
	}
 	
 	ans = l;

//type 3 

      low = 0
      high = N - 1
      while (low <= high) {
          // invariants: value > A[i] for all i < low
                         value < A[i] for all i > high
          mid = (low + high) / 2
          if (A[mid] > value)
              high = mid - 1
          else if (A[mid] < value)
              low = mid + 1
          else
              return mid
      }
      return not_found // value would be inserted at index "low"
  }
  

  Extra credit
Make sure it does not have overflow bugs.

The line in the pseudo-code above to calculate the mean of two integers:

mid = (low + high) / 2
could produce the wrong result in some programming languages when used with a bounded integer type, if the addition causes an overflow. (This can occur if the array size is greater than half the maximum integer value.) If signed integers are used, and low + high overflows, it becomes a negative number, and dividing by 2 will still result in a negative number. Indexing an array with a negative number could produce an out-of-bounds exception, or other undefined behavior. If unsigned integers are used, an overflow will result in losing the largest bit, which will produce the wrong result.

One way to fix it is to manually add half the range to the low number:

mid = low + (high - low) / 2
Even though this is mathematically equivalent to the above, it is not susceptible to overflow.

Another way for signed integers, possibly faster, is the following:

mid = (low + high) >>> 1
where >>> is the logical right shift operator. The reason why this works is that, for signed integers, even though it overflows, when viewed as an unsigned number, the value is still the correct sum. To divide an unsigned number by 2, simply do a logical right shift.

