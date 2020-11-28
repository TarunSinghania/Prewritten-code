multiset<int> m;
m.insert(1);
m.insert(1);
m.insert(1);
m.insert(1);


m.erase(1); will erase alll instances of 1
m.erase(m.find(1)); will erase first intsance of 1