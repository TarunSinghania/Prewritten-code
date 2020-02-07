#include <iostream>
#include<string>
#define FOR(i,a,b) for(int i = a ; i< b ;i++)

bool issmallchar(char a) {
    if(int(a)>=97 && int(a) < 122)
    return true
    else
    return false
}

bool islargechar(char a) {
    if(int(a)>=65 && int(a) < 91)
    return true
    else
    return false
} 

bool isnum (char a ){
    
      if(int(a)>=48 && int(a) < 58)
    return true
    else
    return false
    
}

using namespace std;

int main() {        
    string s  ;    
    cin>>s;
    int r  ;
    cin>>r;
    
FOR(i,0,s.length())
{
    if(isnum(s[i])) {
    int rn = r%10 ;
    int asciinew = int(s[i])+rn 
    if(asciinew>57)
    asciinew= 48+ (asciinew - 57 ) -1 ;
    cout<<char(asciinew);
    }
    else if (issmallchar(s[i]))
    {
        int rn = r%26 ;
        int asciinew = int(s[i])+rn 
        if(asciinew>122)
        asciinew= 97+ (asciinew -122 ) -1 ;
        cout<<char(asciinew);
        
    }    
    else if(islargechar(s[i]))
    {
        int rn = r%26 ;
        int asciinew = int(s[i])+rn 
        if(asciinew>90)
        asciinew= 65+ (asciinew -90 ) -1 ;
        cout<<char(asciinew);
    }
    else
    cout<<s[i];
}    
   
    
	return 0;
}