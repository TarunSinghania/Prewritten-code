vector<vector<int> > v;
void f(Node* r,int l)
{   
    if(!r)
        return;
    
    if((int)v.size()<=l){
        vector<int> h;
        v.push_back(h);
    }
    v[l].push_back(r->data);
    f(r->left,l+1);
    f(r->right,l);
}

void diagonalPrint(Node *root)
{
vector<vector<int> > l;
vector<int> k;
l.push_back(k);
v=l;
 f(root,1);
 for(int i = 0;i < v.size() ; i++)
 {
    for(int j =0; j<v[i].size();j++)
        cout<<v[i][j]<<" ";
 }
    
}
