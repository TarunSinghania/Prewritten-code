int mn =0;int mx =0;
//pair val level
unordered_map<int,pair<int,int> > mp;
void tp(Node* root,int l,int h){
    if(!root)  
        return;
    if(mp.find(l)==mp.end())
    mp[l]=make_pair(root->data,h);
    else
    {
        if(mp[l].second<=h)//< or <= if multiple nodes wheter left most or right most
        mp[l]=make_pair(root->data,h);
    }
    mn = min(mn,l);
    mx = max(mx,l);
    tp(root->left,l-1,h+1);
    tp(root->right,l+1,h+1);
}
void bottomView(struct Node *root)
{
    mn=0;mx=0;
    unordered_map<int,pair<int,int> > m;
    mp = m;
    tp(root,0,0);
    for(int i = mn; i <=mx;i++)
    {
        cout<<mp[i].first<<" ";
    }
}