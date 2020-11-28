


 while using ternary 
 (i>1) 30 :12 ;

 return 30 if i>1 else return 20 



multipltying each multiplication , division blcok by 1.0 , 1ll converts it into double , long long respectively.




  m[i][j] =  1.0*j/(i+j) + 1.0*i/(i+j)*(i-1)/(i+j-1)*m[i-2][j];
                block 1           block 2 

as per operator precdence :
    
  no 1 ++ ,-- 

    no 2 () gets evaluated :
      i+j = z; i-1 = k  i+j-1 = a
      
      =  1.0*j/z + 1.0*i/z*k/a*m[i-2][j];


   no 3 []

    =  1.0*j/z + 1.0*i/z*k/a*val;

    no 4 */ 
    =  block1 + block2 

    so we need to type cast eacch block to double before 

    if we do only one then wrong eg: 1.0*j/(i+j) + i/(i+j)*(i-1)/(i+j-1)*m[i-2][j];

                                ==  double _+ int val 
                                == net double but calc mistake



also 

do not 

  m[i][j] =  1.0*j/(i+j) + (i>1) ? 1.0*i/(i+j)*(i-1)/(i+j-1)*m[i-2][j] : 0;

  instead
   m[i][j] =  1.0*j/(i+j) + ((i>1) ? 1.0*i/(i+j)*(i-1)/(i+j-1)*m[i-2][j] : 0 ) ;

   make sure first ternary gets executed 