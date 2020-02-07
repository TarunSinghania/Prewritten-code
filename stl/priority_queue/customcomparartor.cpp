priority_queue<Node, vector<Node>, Compare> openSet;



priority_queue<Node, vector<Node>, Compare()> openSet;
priority_queue<Node, vector<Node>, bool Compare()> openSet;
priority_queue<Node, vector<Node>, Compare<Node, Node>> openSet; 

all tthis would give error


class Foo
{

};

class Compare
{
public:
    bool operator() (Foo, Foo)
    {
        return true;
    }
};

int main()
{
    std::priority_queue<Foo, std::vector<Foo>, Compare> pq;
    return 0;
}


shiuld use this




example



class cmp
{
public:
	bool operator()(pair<int,int> a , pair<int,int> b)
	{
		return;
	}


};



priority_queue<pair<int,int> , vector<pair<int,int> > , cmp ) v;
















