       
#include<bits/stdc++.h>
#define  mkp make_pair
using namespace std;
enum heaptype{MAX_HEAP,MIN_HEAP};

struct heap{
    int *array;
    int count;
    int capacity;
    int heap_type;
};

struct heap *createheap(int capacity,enum heaptype type)
{
    struct heap *h = (heap *)malloc(sizeof(struct heap));
    if(h == NULL)
            cout<<"memory error",exit(0);
    h->heap_type = type;
    h->count =0;
    h->capacity = capacity;
    h->array = (int*)malloc(sizeof(int)*h->capacity);
    for(int i = 0 ; i < capacity;i++)
    {
        if(h->heap_type == MIN_HEAP)
            h->array[i]=INT_MAX;
        else
            h->array[i]=INT_MIN;
    }
    if(h->array == NULL)
            cout<<"couldnt allocate memory for array",exit(0);
    return h;

}

typedef struct heap heap;

int parent(heap *h,int i)
{
    if(i<=0 || i>= h->count)
        return -1;
    return i-1/2;
}

int lc( heap *h,int i){
    int left=2*i+1;
    if(left>=h->count)
        return -1;
    return left;
}

int rc(heap *h,int i){
    int right=2*i+2;
    if(right>=h->count)
        return -1;
    return right;
}


int gettop(heap *h)
{
    if(h->count == 0)
        return -1;
    return h->array[0];
}

void printheap(heap *h)
{
    for(int i = 0 ; i < h->capacity;i++)
        {
            cout<<h->array[i]<<" ";
        }
    cout<<endl;
}
void prelocatedownmax(heap *h,int i){

    int l,r,max,temp;
    l = lc(h,i);
    r = rc(h,i);
    if(l!=-1 && h->array[l] > h->array[i])
        max =l;
    else
        max = i;
    if(r!=-1 && h->array[r] > h->array[max])
        max = r;
    if(max!=i)
    {
        temp = h->array[i];
        h->array[i]=h->array[max];
        h->array[max]=temp;
        prelocatedownmax(h,max);
    }
}
void prelocatedownmin(heap *h,int i )
{
    int l,r,min,temp;
    
    l = lc(h,i);
    r = rc(h,i);
    if(l!=-1 && h->array[l] < h->array[i])
        min =l;
    else
        min = i;
    if(r!=-1 && h->array[r] < h->array[min])
        min = r;
    if(min!=i)
    {
        temp = h->array[i];
        h->array[i]=h->array[min];
        h->array[min]=temp;
        prelocatedownmin(h,min);
    }
}
void prelocatedown(heap *h,int i )
{
    if(h->heap_type == MAX_HEAP)
        prelocatedownmax(h,i);
    else
        prelocatedownmin(h,i);
}
void resizeheap(heap *h){

    int capacity = h->capacity;
    int * newa  = (int*)malloc(sizeof(int)*capacity*2);
    for(int i = 0 ; i < capacity ; i ++)
    {
        newa[i] = h->array[i];
    }
    free(h->array);
    h->array = newa;
     cout<<"resize done"<<endl;
    if(h->array == NULL)
            cout<<"couldnt allocate memory for array while resizeheap",exit(0);
    
}
void resizeheapandnull(heap *h,int n){
    int capacity = h->capacity;
    while(n>capacity)
        capacity=capacity*2;

    int * newa  = (int*)malloc(sizeof(int)*capacity);
    for(int i = 0 ; i < capacity ; i ++)
    {
        if(h->heap_type == MIN_HEAP)
            h->array[i]=INT_MAX;
        else
            h->array[i]=INT_MIN;
    }
    free(h->array);
    h->array = newa;
    if(h->array == NULL)
            cout<<"couldnt allocate memory for array while resizeheap",exit(0);
    
}

void buildheap(heap *h,int a[],int n)
{

    if(h==NULL)
        cout<<"build heap failed",exit(0);
    resizeheapandnull(h,n);
    h->count = n;
    for(int i = 0 ;i<n;i++)
        h->array[i]=a[i];
    h->count =n;
    for(int i = (n-1)/2; i>=0;i--)
        {
            if(h->heap_type == MIN_HEAP)
                prelocatedownmin(h,i);
            else
                prelocatedownmax(h,i);
        }
}
void insertmax(heap *h,int data,int i)
{
while(i>0 && data > h->array[(i-1)/2])
{
    h->array[i]=h->array[(i-1)/2];
    i = (i-1)/2;
}
h->array[i]=data;
}


void insertmin(heap *h,int data,int i)
{
while(i>0 && data < h->array[(i-1)/2])
{
    
    h->array[i]=h->array[(i-1)/2];
    i = (i-1)/2;
}

h->array[i]=data;
}
void insert(heap *h,int data)
{
    if(h->count == h->capacity) 
        resizeheap(h);
    h->count++;
    int i = h->count -1;
    
    if(h->heap_type == MIN_HEAP)
        insertmin(h,data,i);
    else
        insertmax(h,data,i);
    
}


int deletetop(heap *h)
{
if(h->count == 0)
    cout<<"Cannot pop of empty heap",exit(0);
int temp = h->array[0];
if(h->count==1){
    h->count=0;
   if(h->heap_type == MAX_HEAP)
    h->array[0]  = INT_MIN;
    else
    h->array[0]  = INT_MAX;
    return temp;
}
h->array[0]=h->array[h->count-1];

if(h->heap_type == MAX_HEAP)
h->array[h->count-1]  = INT_MIN;
else
h->array[h->count-1]  = INT_MAX;
h->count=h->count-1;
prelocatedown(h,0);
return temp;
}
int main(){
    
    int t;
    cin>>t;
    while(t--)
    {
        int k;
    cin>>k;
    int n;
    cin>>n;
    
    heap *minheap  = createheap(n,MIN_HEAP);
    for(int i =0 ; i < n;i++)
    {int x;
        cin>>x;
       if(i<k-1){
        cout<<"-1"<<" ";
        insert(minheap,x);
        }
        else if (i==k-1)
        {
            insert(minheap,x);
            cout<<gettop(minheap)<<" ";
        }
        else{
          //  cout<<"%"<<i<<" "<<minheap->array[0]<<endl;
            if(gettop(minheap)<x || gettop(minheap)==INT_MAX)
                deletetop(minheap),insert(minheap,x);
            cout<<gettop(minheap)<<" ";
        }
    }
    cout<<endl;
    }


    return 0;
}