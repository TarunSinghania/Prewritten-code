long long sceil(long long num,long long den){
  //safe ceil while dividing
  if(num%den==0)
    return num/den;
  if(num >0 && den>0)
    return num/den +1;
  if(num <0 && den<0)
    return num/den + 1;
  return num/den;
  //if you use num + den - 1/den this would fail with negative den
}
long long sfloor(long long num, long long den){
  //safe floor while dividing
  if(num%den==0)
    return num/den;
  if(num >0 && den>0)
    return num/den;
  if(num <0 && den<0)
    return num/den;
  return num/den -1;


}