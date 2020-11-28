 map<Node*,int>m;
int LISS(struct Node *root)
{   
    if(root==NULL)
    return 0;
    if(m.find(root) != m.end())
        return m[root];
    
    if(root->left==NULL && root->right == NULL){
        m[root]=1;return 1;
    }
     int gc =0; 
    if(root->left)
        gc += LISS(root->left->left)+LISS(root->left->right);
    if(root->right)
        gc += LISS(root->right->left)+LISS(root->right->right);
    int ans = max(LISS(root->left)+LISS(root->right),1+gc);
    
    m[root]=ans;
    return ans;
    //Code here
}