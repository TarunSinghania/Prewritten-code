int toint(string s)
{
    int n =0;
    if(s[0]=='-')
    {
        for(int i = 1;i<s.length();i++)
        {
            n = n*10 + ((int)s[i]-48);
        }
        n =-n;
    }
    else
    {
        for(int i=0;i<s.length();i++)
            n = n*10 + ((int)s[i]-48);
    }
    return n;
}
int evalTree(node* r)
{
    if(!r)
        return 0;
    
    if(!r->left && !r->right)
        return toint(r->data);
    
    int ll = evalTree(r->left);
    int rr = evalTree(r->right);

    if(r->data == "+")
    {
        return ll+rr;
    }
    else if(r->data == "-")
    {
        return ll-rr;
    }
    else if(r->data == "*")
    {
        return ll*rr;
    }
    else
    {
        return ll/rr;
    }
}

