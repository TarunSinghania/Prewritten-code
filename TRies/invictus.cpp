//@invictus_ clean_code thanks
//when writing trie code in interview make sure to do two modifications added below
#include <bits/stdc++.h>
using namespace std;
#define dbg(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " = " << a << endl;
	err(++it, args...);
}
typedef long long ll;
struct TrieNode {
	TrieNode *bit[2];
	int cnt;
	TrieNode() {
		bit[0] = bit[1] = NULL;
		cnt = 0;
	}
};
TrieNode *root;
void add(int x) {
	TrieNode* cur = root;
	for(int i=30;i>=0;i--)
	{
		int b = (x>>i) & 1;
		if(!cur->bit[b])
			cur->bit[b] = new TrieNode();
		//modification 1
		//doing cnt++ before helps storing correct cnt value in root
		cur->cnt++;
		cur = cur->bit[b];
	}
	//last node update
	cur->cnt++;
}

void remove(int x) {
	TrieNode *cur = root;
	//root wont be cleared since it always has one lement
	for(int i = 30; i >= 0; i --) {
		int b = (x >> i) & 1;
		TrieNode *temp =  cur->bit[b];
    
		if(cur->bit[b]->cnt-1 == 0)
			cur->bit[b]=NULL;//used == instead of = xD
		cur->cnt--;
		//add free function 
		if(cur && cur->cnt==0){
		    free(cur);
		}
			
		cur = temp;
	}
}
int query(int x) {
	TrieNode *cur = root;
	int ans = 0;
	for(int i = 30; i >= 0; i --) {
		int b = (x >> i) & 1;
		if(cur->bit[b] != NULL && cur->bit[b]->cnt > 0) {
			cur = cur->bit[b];
		}
		else {
			ans += 1 << i;
			if(cur->bit[b^1]!=NULL){
			cur = cur->bit[b^1];    
			}
			
		}
	}

	remove(x^ans);
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	root = new TrieNode();
	int t;
	cin >> t;
	int a[t];
	for(int i = 0 ; i < t ; i++){
		cin>>a[i];
	}
	for(int i = 0 ; i < t ; i++){

			int x;
			cin>>x;
			add(x);
	}
	for(int i = 0 ; i < t ; i++){
	 	 cout << query(a[i]) <<" ";
	 }
	return 0;
}