queue


  queue <int> gquiz;
    gquiz.push(10);
    gquiz.push(20);
    gquiz.push(30);



    gquiz.pop();


   gquiz.front() ;

   gquiz.empty();


   template <Typename T >
   void  pq(queue<T> q){

   		while(!q.empty())
   			{ cout<<q.top()<<" "; q.pop()}
   		cout<<endl;   		
   }