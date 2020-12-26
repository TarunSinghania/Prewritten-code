typedef struct{
	
	int s;
	struct process *list;
	(){
		 s= 1;
	};

}semaphore;


wait( semaphore *s){

	s->s--;
	if(s->s<0)
	{
		list.add(process);
		block();
	}	
}


signal(semaphore *s)
{
	s->s++;
	if(s->s<=0)
	{
		struct process p = list.top();
		list.remove(list.top());
		wakeup(p);
	}
}



