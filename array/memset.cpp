   int A[100];
   memset(A,0,sizeof(A)); // all elements of A are zero
   memset(A,-1,sizeof(A)); // all elements of A are -1


- memset is defined in <string.h> and sets the bye values of a block of memory . you can use memset to initialize all elements of an integer array to 0 or -1 but not the other values .


Actually, you can memset correctly with 256 different values, for example, 0x3F3F3F3F.

fill and memset which is faster dpendes on compiler	

fill  supoorts any value 



   int A[100];
   fill(A, A + 100, 7); // A[i] = 7, 0 <= i <= 99