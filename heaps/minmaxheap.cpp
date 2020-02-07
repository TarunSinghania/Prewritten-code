#include<bits/stdc++.h>
#define  mkp make_pair
using namespace std;
enum heaptype{MAX_HEAP,MINHEAP};

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
        if(h->heap_type == MINHEAP)
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
        if(h->heap_type == MINHEAP)
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
            if(h->heap_type == MINHEAP)
                prelocatedownmin(h,i);
            else
                prelocatedownmax(h,i);
        }
}

int main(){
    
    int n;
    cin>>n;
    heap *minheap  = createheap(n,MINHEAP);
    heap *maxheap  = createheap(n,MAX_HEAP);
    int a[n];
    for(int i =0;i<n;i++)
        cin>>a[i];
    buildheap(minheap,a,n);
    buildheap(maxheap,a,n);
    printheap(minheap);
    printheap(maxheap);
    

    

    return 0;
}