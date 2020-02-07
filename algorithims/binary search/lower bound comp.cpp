Returns: The furthermost iterator i in the range [first, last] such that for any iterator j in the range [first, i) the following corresponding conditions hold: *j <
  value or comp(*j, value) != false.




struct node {

	ll startheight , len,range ;

};


bool cmp (node b , ll a){

//cout<<a<<" "<< b.range<<endl;
    return(a>b.range);


}



node s[n];
//sorted with increasing order of range
find least range node greater than or equal v
-------------------------
comp node with value

fails--- true------

node * p  = lower_bound(s,s+n,v,cmp);
