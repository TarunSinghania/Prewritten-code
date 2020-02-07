    unordered_map<string, double> umap;


 umap["PI"] = 3.14;
    umap["root2"] = 1.414;
    umap["root3"] = 1.732;
    umap["log10"] = 2.302;
    umap["loge"] = 1.0;
 




   // inserting value by insert function
    umap.insert(make_pair("e", 2.718));



    if (umap.find(key) == umap.end())
        cout << key << " not found\n\n"


    if (umap.find(key) == umap.end())
        cout << key << " not found\n";



     unordered_map<string, double>:: iterator itr;
    cout << "\nAll Elements : \n";
    for (itr = umap.begin(); itr != umap.end(); itr++)
    {
        // itr works as a pointer to pair<string, double>
        // type itr->first stores the key part  and
        // itr->second stroes the value part
        cout << itr->first << "  " << itr->second << endl;
     }



      std::cout << "mymap.size() is " << mymap.size() << std::endl
      no of Elements