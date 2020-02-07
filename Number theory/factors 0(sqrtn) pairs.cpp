template<class T> vector<pair<T,int>> factor(T x) { // x <= 10^{14} is fine
	vector<pair<T,int>> pri;
 
	for (T i = 2; i*i <= x; ++i) if (x % i == 0) {
		int t = 0;
		while (x % i == 0) x /= i, t ++;
		pri.pb({i,t});
	}
 
	if (x > 1) pri.pb({x,1});
	return pri;
}