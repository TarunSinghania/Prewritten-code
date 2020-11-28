void build(int node,int start,int end,int tree[],int a[])
{
	if(start==end)
	tree[node]=a[start];
	else
	{
	int mid=(start+end)/2;
	build(2*node,start,mid,tree,a);
	build(2*node+1,mid+1,end,tree,a);
	if(tree[2*node]>tree[2*node+1])
	tree[node]=tree[2*node];
	else
	tree[node]=tree[2*node+1];
	}
}

void update(int node,int start,int end,int idx,int val,int tree[],int a[])
{
	if(start==end)
	{
	a[idx]=val;
	tree[node]=val;
	}
	else
	{
	int mid=(start+end)/2;
	if(idx>=start&&idx<=mid)
	update(2*node,start,mid,idx,val,tree,a);
	else
	update(2*node+1,mid+1,end,idx,val,tree,a);
	if(tree[2*node]>tree[2*node+1])
	tree[node]=tree[2*node];
	else
	tree[node]=tree[2*node+1];
	}

}

int query(int node,int start,int end,int l,int r,int tree[])

{
	if(l>end||start>r)
	return INT_MIN;
	
	if(l<=start&&r>=end)
	return tree[node];
	int p1,p2;

	int mid=(start+end)/2;
	p1=query(2*node,start,mid,l,r,tree);
	p2=query(2*node+1,mid+1,end,l,r,tree);

	if(p1>p2)
	return p1;
	else
	return p2;
}


int main()
{

int tree[2000005],a[100005];

int n,q;
cin>>n>>q;
for(int i=1;i<=n;i++)
cin>>a[i];
build(1,1,n,tree,a);
while(q--)
{
char b;
int x,y;
cin>>b>>x>>y;
if(b=='q')
{
int c=query(1,1,n,x,y,tree);
cout<<c<<endl;
}
else
update(1,1,n,x,y,tree,a);
}

return 0;
}




















int dfs[v+1] // original array
int newtree[100001]




void build(int node,int start,int end)
{
  if(start==end)
  newtree[node]=dfs[start];
  else
  {

  int mid=(start+end)/2;

  build(2*node,start,mid);
  build(2*node+1,mid+1,end);

  if(newtree[2*node]>newtree[2*node+1])
  newtree[node]=newtree[2*node];
  else
  newtree[node]=newtree[2*node+1];

  }
}



int query (int node , int start , int end , int l ,int r )
{
  if(l>end || r< start)
    return  INT_MIN ;

  if(l<=start && r <= end )
    return newtree[node];

  int p1 , p2 ;

  p1 = query(2*node,start,mid,l,r);
  p2 = query(2*node,mid+1,end,l,r);

  if(p1>p2)
  return p2;
  else
  return p1 ;


}

//from1 to v stored are vertices in 
//note range is inclusive l,r
build(1,1,v);
//x,y are inputs 
query(1,1,v,x,y);