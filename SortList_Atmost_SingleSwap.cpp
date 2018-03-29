// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
/**
*   Program to check whether the given list is in sorted order(ascending) with at most one swap.
*   example: A[] = [1, 2, 3, 6, 5, 5, 4, 7] using single swap A[3] <-> A[6]
*            After single swap if the list is in sorted order return TRUE, otherwise FALSE
**/ 

bool solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int len = A.size();
    if(len <=1)
        return true;
        
    for(int i = 0; i < len-1; i++)
    {
        if(A[i] <= A[i+1])
        {
            continue;
        }
        if(A[i] > A[i+1])
        {
            int temp = i;
            int j = i + 1;
            while((A[temp] > A[j]) && (j < len-1))
              j++;
            int x = A[temp];
            A[temp] = A[j-1];
            A[j-1] = x;
            break;
        }
    }
    for(int i = 0; i < len-1; i++)
    {
        if(A[i] <= A[i+1])
            continue;
        else
            return false;
    }
 return true;   
    
}