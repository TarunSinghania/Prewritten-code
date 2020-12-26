reder writers problem using semaphore 

semaphore rw_mutex;
sempahore ct_mutex;
int rc;
do {
	
wait(rw_mutex);

//write
signal(rw_mutex);

}while(true);




do{
	
wait(ct_mutex);
if(rc==0)
	wait(rw_mutex);
rc++;
signal(ct_mutex);



//perform read;


wait(ct_mutex);
rc--;
if(rc == 0)
	signal(rw_mutex);
signal(ct_mutex);
}while(true);