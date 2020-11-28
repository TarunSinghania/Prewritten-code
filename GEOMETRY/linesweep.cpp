//basic line sweep (for horizantal and vertical lines intersection)
#include <bits/stdc++.h> 
using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define speed   ios::sync_with_stdio(false), cin.tie(0) , cout.tie(0)
#define fillm(m,r,c,k) fr(i,0,r)fr(j,0,c)m[i][j]=k;
#define prm(m,r,c) fr(i,0,r){fr(j,0,c){cout<<m[i][j]<<" "; }cout<<endl;}
#define pr(a,n)fr(i,0,n)cout<<a[i]<<",";cout<<endl;
#define endl '\n'
#define MOD 1000000007
#define INF 1000000000
#define prv(v) for(auto x: v)cout<<x<<" ";cout<<endl;
#define MAX 1000005
#define all(x) x.begin(),x.end()
#define mkp make_pair 
#define ll long long
#define f first
#define s second

int t[4* MAX];
int s,e;
int ho,ve;
ll ans = 1;
void u(int n,int s,int e,int id,int val)
{
    if(s==e)
    {
        t[n]+=val;
    }
    else
    {
        int m = (s+e)/2;
        if(s<=id && id <=m)
        {
            u(2*n,s,m,id,val);
        }
        else
        {
            u(2*n+1,m+1,e,id,val);
        }

        t[n]=t[2*n]+t[2*n+1];
    }

}
int q(int n,int s,int e,int l,int r){
    
    if(r< s || e <l)
    {
        return 0;
    }
    if(l<= s && e<=r)
    {
        return t[n];
    }
    int m= (s+e)/2;

    int p1 = q(2*n,s,m,l,r);
    int p2 = q(2*n+1,m+1,e,l,r);
    return (p1+p2);

}
void update(int id,int v){
	u(1,s,e,id,v);
}

int query(int l,int r){
	return q(1,s,e,l,r);
}

class hline{
public:
	int y,l,r;
	hline(int a,int b,int c){
		y = a;l = b;r = c;
	}
	bool operator < (const hline &hl){
		return (l < hl.l);
	}
};
class vline{
public:
	int x,u,d;
	vline(int a,int b,int c){
		x = a;d = b;u = c;
	}
	//DO NOT USW WITH SET 
	bool operator <	 (const vline & vl){
		return (x < vl.x);
	}
};
//USE THIS WITH SET
struct comp{	
    bool operator()(const hline &a,const hline &b){
    		if(a.r!=b.r)
    		return a.r < b.r;
    		else if(a.l!=b.l)
    		return a.l < b.l;
    		else
    		return a.y < b.y;
    }
};

vector<hline> h;
vector<vline> v;

void linesweep(){
	set<hline,comp> memory;
	int hid =0;int vid=0;
	int er =0;
	fr(cx,0,1000005){
	    while(!memory.empty()){
		 	if((memory.begin()->r)<cx){
				er++;
				update(memory.begin()->y,-1);
		 		memory.erase(memory.begin());
		 	}
			else{
				break;
			}
		}	

		while(hid < h.size()){
			if(h[hid].l > cx)
				break;
			memory.insert(h[hid]);
			update(h[hid].y,1);		
			hid+=1;
		}
		while(vid < v.size()){
			if(v[vid].x > cx)
				break;
			ans += query(v[vid].d,v[vid].u);
			vid+=1;
		}
	}
}

main(){
	s = 0;
	e = 1000005;
	cin>>ho>>ve;
	fr(i,0,ho){
		int y,l,r;
		cin>>y>>l>>r;
		if(l==0 && r== 1000000)
			ans += 1;
		h.pb(hline(y,l,r));
	}
	fr(i,0,ve){
		int x,u,d;
		cin>>x>>d>>u;
		v.pb(vline(x,d,u));
		if(d==0 && u== 1000000)
			ans += 1;
	}
	sort(all(h));
	sort(all(v));
	linesweep();
	cout<<ans<<endl;	
}