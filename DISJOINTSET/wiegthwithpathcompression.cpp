//modified initialize function:
    void initialize( int Arr[ ], int N)
    {
        for(int i = 0;i<N;i++)
        {
    Arr[ i ] = i ;
    size[ i ] = 1;
    }
    }



//modified root function
    
Union with path compression

While computing the root of A, set each i to point to its grandparent (thereby halving the length of the path), where i is the node that comes in the path while computing the root of A.


    int root (int Arr[ ] ,int i)
    {
        while(Arr[ i ] != i)
        {
            Arr[ i ] = Arr[ Arr[ i ] ] ; 
    i = Arr[ i ]; 
        }
    return i;
    }



    void weighted-union(int Arr[ ],int size[ ],int A,int B)
    {
        int root_A = root(A);
        int root_B = root(B);

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






	bool find(int A,int B)
    {
        if( root(A)==root(B) )       //if A and B have the same root, it means that they are connected.
        return true;
        else
        return false;
    }
