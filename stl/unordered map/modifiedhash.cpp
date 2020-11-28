
struct HASH{
  size_t operator()(const pair<int,int>&x)const{
    return (size_t) x.first * 37U + (size_t) x.second;
  }
};



struct StringHasher {
    size_t operator()(const std::string& t) const {
          //calculate hash here.
    }
}

unordered_map<std::string, ValueType, StringHasher>


struct HASH{
  size_t operator()(const pair<int,int>&x)const{
    return hash<long long>()(((long long)x.first)^(((long long)x.second)<<32));
  	//	return hash<int>()(x.first);
    	
  }
};

unordered_map<pair<int,int>,int,HASH>mp