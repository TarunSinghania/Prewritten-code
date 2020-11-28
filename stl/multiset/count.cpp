
int myints[]={10,73,12,22,73,73,12};
  std::multiset<int> mymultiset (myints,myints+7);


  std::cout << "73 appears " << mymultiset.count(73) << " times in mymultiset.\n";
