boolean test_Ans_Set(boolean *target){
	boolean rv = *target;
	*target = true;
	return rv;
}

s satisfy the mutual-exclusion requirement, they do not satisfy the bounded-waiting requirement

to see bounded_waiting mutual exlusion 


do { 
	while (TestAndSet(&lock)) ; //do nothing 
		
		//critical section 
	lock = FALSE; 
	
		// remainder section
} while (TRUE);


Mutual-exclusion implementation with TestAndSet (