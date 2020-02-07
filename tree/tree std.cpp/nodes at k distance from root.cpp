int a =0;
int h =0;
bool m[105];
vector<int> path;
void f(Node* n)
{
        if(!n)
            return;
        path.push_back(n->key);
        if(n->left == NULL && n->right == NULL)
        {
            if((int)path.size()>=h+1)
                {
                    if(m[path[(int)path.size()-1-h]]!=true){
                        m[path[(int)path.size()-1-h]]=true,a++;
                       // pr(path);
                      //  cout<<path[(int)path.size()-1-h]<<"@"<<n->key<<endl;
                    }
                }
            path.pop_back();     
            return;
        }
        f(n->left);
        f(n->right);
        path.pop_back();
}
int printKDistantfromLeaf(Node* node, int k)
{
    //Add your code here. 
    h =k;
    a =0;
    for(int i= 0; i < 105 ;i++)
        m[i]=false;
    f(node);
    return a;
}