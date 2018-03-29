// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
/**
* Program : Find the depth of the distinct path in the binary tree
*           Return the depth
**/

#include <bits/stdc++.h>
int largestUinquePathUtil(tree * Root, unordered_map<int, int> tab)
{
    if (!Root)
        return tab.size();
    tab[Root->x]++;
    int dist_path = max(largestUinquePathUtil(Root->l, tab),
                       largestUinquePathUtil(Root->r, tab));
    tab[Root->x]--;
    if (tab[Root->x] == 0)
        tab.erase(Root->x);
    return dist_path;
}
int solution(tree * T) {
    // write your code in C++14 (g++ 6.2.0)
    int res = 0;
    if(T == NULL)
        return res;
    else
    {
        unordered_map<int, int> hash; 
        return largestUinquePathUtil(T, hash);
    }
  }