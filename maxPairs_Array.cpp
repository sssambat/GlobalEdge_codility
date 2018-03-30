/** 
*  problem : toggle one position to get maximum pairs of same values
*  return - no of pairs of same values
*  example: 101010000 -> 101000000, returns 5
*  example: 100010000 -> 100000000, returns 7
*  example: 101011111 -> 101111111, returns 6
**/

int solution(vector<int> & A) {
    int n = A.size();
    int result = 0;
    for (int i = 0; i < n - 1; i++) {
        if (A[i] == A[i + 1])
            result = result + 1;
    }
    int r = -1;
    for (int i = 0; i < n; i++) {
        int count = 0;
        if (i > 0) {
            if (A[i - 1] != A[i])
                count = count + 1;
            else
                count = count - 1;
        }
        if (i < n - 1) {
            if (A[i + 1] != A[i])
                count = count + 1;
            else
                count = count - 1;
        }
        r = max(r, count);
    }
    return result + ((n > 1 && r == 0) ? -1 : r);
}
