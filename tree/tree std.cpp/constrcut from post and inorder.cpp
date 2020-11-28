#include<bits/stdc++.h>
#define pr(v) for(auto x: v){cout<<x<<" ";}cout<<endl;
using namespace std;

struct node {

    int d;
    struct node* left; 
    struct node* right;
    node(int val){
        d = val;
        left=NULL;
        right=NULL;
    }

};

typedef struct node node;
vector<int> vin,vpost,vpre;

void post(node * n)
{
    if(!n)
        return;

    post(n->left);
    post(n->right);
    vpost.push_back(n->d);
}

void in(node * n)
{
    if(!n)
        return;
    cout<<n->d<<endl;
    in(n->left);
    vin.push_back(n->d);
    in(n->right);
}
void pre(node *n)
{

    if(!n)
        return;
    vpre.push_back(n->d);
    pre(n->left);
    pre(n->right);
}

int f (int v,int s,int e){

    for(int i = s; i <=e; i++)
        if(vin[i]==v)
            return i;

    cout<<"TREE IMPOSSIBLE"<<endl;
    return -1;
}


node * construct(int s,int e,int p)
{
    cout<<s<<" "<<e<<"called"<<p<<endl;
    if(s>e)
        return NULL;
    if(s==e)   {
        node * r = new node(vpost[p]);
        return r;
    }
    int id  = f(vpost[p],s,e);
    cout<<p<<" "<<id<<endl;
    node *r = new node(vpost[p]);
    r->left = construct(s,id-1,p-(e-id)-1);
    r->right =construct(id+1,e,p-1);
    return r;
}



int main()
{
     node * root= new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->right->left = new node(6);
    root->left->right->right = new node(7);
    root->right->left = new node(8);
    root->right->right = new node(9);
    //in(root);post(root);
   // pr(vin);
   // pr(vpost);
    int n;
    cin>>n;
   for(int i =0;i< n;i++)
   {
    int x;
    cin>>x;
    vin.push_back(x);
   }
for(int i =0;i< n;i++)
   {int x;
    cin>>x;
    vpost.push_back(x);
   }
  node* r  = construct(0,vpost.size()-1,vpost.size()-1);   
  pre(r);
  pr(vpre);
    return 0;
}

