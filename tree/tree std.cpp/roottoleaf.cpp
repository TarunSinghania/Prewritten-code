void pp(vector<int> &v,r)
{
    if(!r)
        return;
    v.push_back(root->data);
    if(v->left==NULL &&v->right ==NULL)
        {
            for(auto x: v)
                cout<<x<<" ";
            cout<<"#";
            return;
        }
    pp(v,r->left);
    pp(v,r->right);
}
void printPaths(Node* root)
{
    
    if(!root)
    return;
    vector<int> v;
    pp(v,root);
    
}