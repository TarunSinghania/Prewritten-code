void mirror(Node* node) 
{
     Node* nl = node->left;
     Node* nr = node->right;
     
     node->left = nr;
     node->right = nl;
     if(nr != NULL)
     mirror(nr);
     if(nl != NULL)
     mirror(nl);
     // Your Code Here
}