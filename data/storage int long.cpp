Specifier(s)         Type
-------------    -------------
long long int    long long int   64Bytes    9 10^18
long long        long long int   64Bytes

long int         long int        32Bytes    2 10^9    
long             long int        32Bytes

int is at least 16 bits
long is at least 32 bits
long long (in versions of the language that support it) is at least 64 bits

int nowadays 32 32Bytes
long also same


long and long int are identical. So are long long and long long int. In both cases, the int is optional.



long long  max   	-9,223,372,036,854,775,808  to 9,223,372,036,854,775,807
usigned              2* up


int -2,147,483,648 to 2,147,483,647


float is a 32 bit IEEE 754 single precision Floating Point Number1 bit for the sign, (8 bits for the exponent, and 23* for the value), i.e. float has 7 decimal digits of precision.

double is a 64 bit IEEE 754 double precision Floating Point Number (1 bit for the sign, 11 bits for the exponent, and 52* bits for the value), i.e. double has 15 decimal digits of precision.

long double 