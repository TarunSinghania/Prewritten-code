//PRODUCER

	do { 
		//produce an item in nextp 
		wait(empty); 
		wait(mutex);
		 // add nextp to buffer 
		signal(mutex); 
		signal(full); 
	} while (TRUE);






//CONSUMER
	do { 
		wait (full); 
		wait (mutex) ; 
		// remove an item from buffer to nextc
		 signal(mutex); 
		 signal(empty);
		 //  consume the item in nextc 
	} while (TRUE); 