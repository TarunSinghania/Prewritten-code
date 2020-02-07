
void initialize( int Arr[ ], int size[ ],int N)
{
        for(int i = 0;i<N;i++)
        {
    Arr[ i ] = i ;
    size[ i ] = 1;
    }
}




     //finding root of an element
  int root(int Arr[ ],int i)
    {
        while(Arr[ i ] != i)           //chase parent of current element until it reaches root
        {
         i = Arr[ i ];
        }
        return (int)i;
    }


 bool find(int A, int B,int Arr[])
    {
        if( root(Arr,A) == root(Arr,B) )       //if A and B have the same root, it means that they are connected.
        return true;
        else
        return false;
    }


  void weighted_union(int Arr[ ],int size[ ],int A,int B)
    {
        int root_A = root(Arr,A);
        int root_B = root(Arr,B);
    
      //cout<<root_A<<"--"<<root_B<<endl;
      if(root_A == root_B)
        return;

    if(size[root_A] < size[root_B ])
        {
    Arr[ root_A ] = Arr[root_B];
    size[root_B] += size[root_A];
    }
        else
        {
    Arr[ root_B ] = Arr[root_A];
    size[root_A] += size[root_B];
    }

    }

  
 

