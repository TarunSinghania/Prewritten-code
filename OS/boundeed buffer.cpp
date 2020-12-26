The Producer Operation

do 
{
    // wait until empty > 0 and then decrement 'empty'
    wait(empty);   
    // acquire lock
    wait(mutex);  
    
    /* perform the insert operation in a slot */
    
    // release lock
    signal(mutex);  
    // increment 'full'
    signal(full);   
} 
while(TRUE)


The Consumer Operatio
do 
{
    // wait until full > 0 and then decrement 'full'
    wait(full);
    // acquire the lock
    wait(mutex);  
    
    /* perform the remove operation in a slot */ 
    
    // release the lock
    signal(mutex); 
    // increment 'empty'
    signal(empty); 
} 
while(TRUE);