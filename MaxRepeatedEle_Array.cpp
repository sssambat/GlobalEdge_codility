#include <malloc.h>
#include <iostream>
using namespace std;
int solution(int M, int A[], int N) {
    int *count = (int *)malloc((M+1) * sizeof(int));
    int i;
    for (i = 0; i <= M; i++)
        count[i] = 0;
    int maxOccurence = 1;
    int index = -1;
    for (i = 0; i < N; i++) {
        if (count[A[i]] > 0) {
            int tmp = count[A[i]];
            if (tmp >= maxOccurence) {
                maxOccurence = tmp;
                index = i;
            }
            count[A[i]] = tmp + 1;
        } else {
            count[A[i]] = 1;
        }
    }
    return A[index];
}
int main()
{
	int res;
	int M =3, A[5] = {1,2,3,3,2};
	res = solution(M, &A[0], 5);
	cout<<"result"<<res<<endl;
	return 1;
	
}
