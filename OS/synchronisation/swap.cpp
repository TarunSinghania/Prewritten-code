void Swap(boolean *a, boolean *b) { 
	boolean temp = *a;
	 *a = *b; 
	 *b = temp;
}



do { 
	key = TRUE; 
	while (key == TRUE) 
		Swap(&lock, &key); 
	//critical section 
	lock = FALSE; 
	//remainder section

 } while (TRUE);