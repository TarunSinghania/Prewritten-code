 stack <int> gquiz;

 gquiz.push(20);
 


 cout<<gquiz.top()<<endl;
//check before if top exisets or not otherwise segementation fault 
//A reference to the top element in the stack. returs refernce  


  mystack.top() -= 5;

 

stack< int > numbers;
numbers.push( 1 );
numbers.push( 2 );

while ( not numbers.empty( ) )
{
    int number = numbers.top( );
    numbers.pop( );
}

//cant iterate thorug stack using iterator
 

//no changes in stack passed as copy 
void ps( stack<int> s){
    while(!s.empty())
       { cout<<s.top()<<" ";
        s.pop();        
        }   
        cout<<endl;
}


