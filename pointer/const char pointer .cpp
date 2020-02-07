
const char *ptr : This is a pointer to a constant character. You cannot change the value pointed by ptr, but you can change the pointer itself. “const char *” is a (non-const) pointer to a const char.


// C program to illustrate 
// char const *p
#include<stdio.h>
#include<stdlib.h>

int main()
{
    char a ='A', b ='B';
    const char *ptr = &a;
    
    //*ptr = b; illegal statement (assignment of read-only location *ptr)
    
    // ptr can be changed
    printf( "value pointed to by ptr: %c\n", *ptr);
    ptr = &b;
    printf( "value pointed to by ptr: %c\n", *ptr);
}



char *const ptr : This is a constant pointer to non-constant character. You cannot change the pointer p, but can change the value pointed by ptr.
// C program to illustrate 
// char* const p
#include<stdio.h>
#include<stdlib.h>

int main()
{
    char a ='A', b ='B';
    char *const ptr = &a;
    printf( "Value pointed to by ptr: %c\n", *ptr);
    printf( "Address ptr is pointing to: %d\n\n", ptr);

    //ptr = &b; illegal statement (assignment of read-only variable ptr)

    // changing the value at the address ptr is pointing to
    *ptr = b; 
    printf( "Value pointed to by ptr: %c\n", *ptr);
    printf( "Address ptr is pointing to: %d\n", ptr);
}



const char * const ptr : This is a constant pointer to constant character. You can neither change the value pointed by ptr nor the pointer ptr.
// C program to illustrate 
//const char * const ptr 
#include<stdio.h>
#include<stdlib.h>

int main()
{
    char a ='A', b ='B';
    const char *const ptr = &a;
    
    printf( "Value pointed to by ptr: %c\n", *ptr);
    printf( "Address ptr is pointing to: %d\n\n", ptr);

    // ptr = &b; illegal statement (assignment of read-only variable ptr)
    // *ptr = b; illegal statement (assignment of read-only location *ptr)

}


