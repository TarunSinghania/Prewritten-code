do{

waiting[i]=true;
key = true;
while(waiting[i] && key)
	key = test_and_Set(&lock);
waiting[i]=false;

CS


j = (i+1)%n;
while(j!=i && !waiting[j])
		j = (j+1)%n;
if(j==i)
	lock = false;
else 
	waiting[j]= false;

}while(true);


//for i process