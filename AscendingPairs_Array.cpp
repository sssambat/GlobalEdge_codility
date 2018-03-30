int solution(int[] A, int N)
{
int maxSliceStart = 0;
int maxSliceLength = 1;

int currentSliceStart = 0;

for (int i = 1; i < N; i++)
{
    if (A[i - 1] >= A[i]) currentSliceStart = i;

    if (i - currentSliceStart + 1 /* length of the current slice */ > maxSliceLength)
    {
        maxSliceStart = currentSliceStart;
        maxSliceLength = i - currentSliceStart + 1;
    }
}

return maxSliceStart;
}
