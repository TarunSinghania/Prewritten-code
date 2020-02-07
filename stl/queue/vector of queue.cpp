vector of queue

	queue<int> qo;
	vector<queue<int> > qu(5);

	that means 0 to 4 you have qu[0];qu[1];qu[2];qu[3];

	vector<queue < pair<int,int> > > qu(5)


	cout<<qu[qo.front()].front().first<<" "<<qu[qo.front()].front().second<<endl;
			qu[qo.front()].pop();