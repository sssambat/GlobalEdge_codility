/**
* problem : Stack Machine operation
* input : string of stack operation
* return - top element in the stack
*
* example: 1. 30 10 DUP + - 5 POP
*           30				  		30
*           30 10	   			    30 10 
*           30 10 DUP 		 		30 10 10
*           30 10 DUP + 			30 20
*           30 10 DUP + - 			10
*           30 10 DUP + - 5			10 5
*           30 10 DUP + - 5 POP 	10
* example: 2. 30 -, return -1, invalid operation
* example: 3. DUP, return -1, invalid operation
* example: 4. POP, return -1, invalid operation
* example: 5. 10 20 -, return -1, invalid operation
**/

int solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    int length = 0, j = 0, k = 0, A[20]= {0};
    char str1[20][5];
    length = S.size();
    for(int i = 0; i < length; i++)
    {
        if(S[i] != ' ')
        {
            str1[j][k] = S[i];
            k++;
        }
        else
        {
            str1[j][k] = '\0';
            j++;
            k = 0;
        }
    }
    str1[j][k] = '\0';
    j++;
    int m = 0;    
    for(int i = 0; i<j; i++)
    {
        string st(str1[i]);
        if((st.compare("DUP")) == 0)
        {
            if(m < 1)
            {
                return -1;
            }
            else
            {
             int temp = A[m];
                A[++m] = temp;
            }
        }
        else if((st.compare("POP")) == 0)
        {
            if(m < 1)
            {
                return -1;
            }
            else
            {
                m--;
            }    

        }
        else if((st.compare("+")) == 0)
        {
            if(m < 2)
            {
                return -1;
            }
            else
            {
               
                int temp = A[m - 1];
                A[m-1] = A[m] + temp;
                A[m] = 0;
                m--;
            }
        }
        else if((st.compare("-")) == 0)
        {
            if(m < 2)
            {
                return -1;
            }
            else
            {
               int temp = A[m - 1];
               A[m-1] = A[m] - temp;
               A[m] = 0;
               m--;
            }
                
        }
        else
        {
            A[++m] = stoi(st);    
        }
    }
    if(A[m]>=0)
        return A[m];
    else
        return -1;
}
