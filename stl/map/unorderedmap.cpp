 unordered_map<int,int> m;

 m[nums[i]] = i;

if(m.find(target - nums[i]) != m.end())

m.find(target-nums[i])->second;