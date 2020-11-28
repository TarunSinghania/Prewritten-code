

largest num smaller than num 

int nextsmall(int loc , int num){
      
     int s =  ar[num].size();
     //c(s,"size");      
      int low = 0 , high = s -1 ;
      int ns = -1;
      while(low<=high)
      {
          int mid = (low+high)/2;
        
            if(ar[num][mid] < loc)
            {   ns = mid ;
                low = mid+1;}
            else
            high = mid -1 ;
      }
      if(ns!=-1)
      return ar[num][ns];
    else
        return -1;
      //cout<<loc<<endl;
    
}




int lesser_num(std::vector<int> v, int num )
{
    int s =  v.size();
           
      int low = 0 , high = s -1 ;
      int ns = -1;
      while(low<=high)
      {
          int mid = (low+high)/2;
        
          if(v[mid] < num)
            {  ns = mid ;
              low = mid+1;
            }
            else
            high = mid -1 ;
      }
      if(ns!=-1)
      return v[ns];
    else
        return -1;


}


//binary search a num between 1 to l ..minimum number whose N*log(number) > sum 




if(sum==0){   ///base case for 1 
  cout<<1<<endl;
  return 0;}

while(low<=high)
{
  long long mid = (low+high)>>1;
  //c(mid,"mid");
    
    if( n*log(mid) > sum )
      {
        if(n*log(mid-1)<sum){
       ans= mid;break;}
      high = mid ;
      }
    else
      low = mid+1 ;
}
if(ans!=-1)  
cout<<ans<<endl;
else
cout<<low<<endl; case when l 
