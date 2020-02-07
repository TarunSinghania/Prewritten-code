Motivation: Given an array of N integers. You have to answer some queries in form (l, r, k). To answer this query you have to print the number of integers less than k in the sub-array array[l .... r].

You should be able to solve the problem in O(log^2 n) per query at least. How? You can use Merge Sort Trees.

Now what is a Merge Sort Tree? Merge Sort Tree is actually a Segment Tree but each node contains a vector. If the range of the node is [l,r] then the vector will contain the elements of array[l...r] but in sorted order.

To solve the above problem we can make a Merge Sort Tree first and go into relevant segments and binary search on the vector that was stored in those nodes to count how many numbers are less than k. This will give O(log^2 n).