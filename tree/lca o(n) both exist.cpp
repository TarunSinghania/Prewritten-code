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