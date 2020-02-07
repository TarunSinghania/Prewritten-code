What is a structure pointer?
Like primitive types, we can have pointer to a structure. If we have a pointer to structure, members are accessed using arrow ( -> ) operato




struct Point
{
   int x, y;
};
 
  struct Point p1 = {1, 2};
  

  struct Point *p2 = &p1;