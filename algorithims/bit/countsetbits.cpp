
#include<bits/stdc++.h>
using namespace std;

int csb(long long int x)
{
	int c = 0;
	while(x)
		{	
			c += x & 1;
			x >>= 1;
			cout<<x<<endl;
		}

	return c;

}

int main()
{
	
cout<<csb(256)<<endl;


return 0;
}