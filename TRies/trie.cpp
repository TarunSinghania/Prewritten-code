#include<bits/stdc++.h>
using namespace std;
struct trie{
    bool end;
    map< char, trie*> child;
    trie(){
        end = false;
        child.clear();
    }
};
 
void insert(trie *root, string s){
   
    
    for(int i =0; i<(int)s.length(); i++){
        if(root->child[s[i]] == NULL)
            root->child[s[i]] = new trie();
        root = root->child[s[i]];
    }
 
    root->end = true;
}
 
void erase(trie *root, string s){
    
    
    for(int i =0; i<(int)s.length(); i++){
        if(root->child[s[i]] == NULL)
            root->child[s[i]] = new trie();
        root = root->child[s[i]];
    }
 
    root->end = false;
}
 
 
bool search(trie *root, string s){
    
    for(int i =0; i<(int)s.length(); i++){
        if(root->child[s[i]] == NULL)
            return false;
        root = root->child[s[i]];
    }
    return  root->end;
}
 
    bool solve(string current, trie *root){
                 if(current.length() == 0) return true;
        
        int len = current.length();
       // cout<<current<<"$$"<<endl;
        for(int i = 1; i<=len;i++){
            
            string fs = current.substr(0,i);
            string rs = current.substr(i, len - i);
           // cout<<current<<"#"<<i<<fs<<" "<<rs<<endl;
            if(search(root,fs))    
            {    
                //erase(root,fs);
                if(solve(rs,root)){
                //cout<<current<<"% "<<fs<<" "<<rs<<endl;
                return true;
                }
                //insert(root,fs);
            }
        }
     
        return false;
    }
int main(){
    int n;
    cin >> n;
    
    trie *root = new trie();
    vector<string> a, r;
 string s;
    for(int i=0; i<n;i++){
        cin >> s;
        insert(root, s);
        a.push_back(s);
    }
 
    for(int i =0; i<n;i++){
        string current = a[i];
            erase(root,current);
        if(solve(current, root)){
            r.push_back(current);
        }
            insert(root,current);
    }
 
           
            for(int i = 0;i<(int)r.size();i++){
                cout << r[i] << " ";
            }
            return 0;
}