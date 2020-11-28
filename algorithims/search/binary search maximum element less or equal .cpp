
int l //sratt index
int r //endindex
int mek //value of max possible or less than it


 int b = -1;

    
    while(l<=r)
    {
      if(l==r-1)
      {
        if(a[l]<=mek)b= l;
        if(a[r]<=mek)b= r ;

        break;
      }

      if(l==r)
        {  if(a[l]<=mek)b = l;   break;}
      
      int m = l + (r-l)/2;

      if(a[m]<=mek)
        l = m ;
      else
        r = m -1 ;
    }
