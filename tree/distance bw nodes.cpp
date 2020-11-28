 Node * lca(Node* root ,int n1 ,int n2 )
{
    if(root==NULL)
        return NULL;
  
    if(root->data == n1)
            return root;
    if(root->data == n2)
            return root;
    Node * l = lca(root->left,n1,n2);
    Node * r = lca(root->right,n1,n2);
    
    if(l!=NULL && r!=NULL)
            return root;
    else if(l==NULL)
            return r;
    else
            return l;

    //if one node doesnt exist then it returns the other node index conidering the node to be in its subtree
}
int dis(Node* root,int a)
{
    if(!root)
        return -1;
    if(root->data == a)
        return 0;
    int l = dis(root->left,a);
    int r = dis(root->right,a);
    if(l==-1 && r==-1)
        return -1;
    if(l!=-1)
        return l+1;
    else
        return r+1;
}
int findDist(Node* root, int a, int b)
{
    Node* lc = lca(root,a,b);
    int l = dis(lc,a);
    int r = dis(lc,b);
    return l+r;
}