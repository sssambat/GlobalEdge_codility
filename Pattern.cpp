/**
*  problem: 
*    ABBABC-> AABC-> BC
*    ABABAB-> ABABAB
*    AABBCC-> empty
*
*/

string solution(string &S) {
    int len = S.length(), temp;
    if(len <= 1)
        return S;
    else
    {
       do
        {   
            temp = len;
            for(int i= 0; i<len-1;i++)
            {               
                if(S[i] == S[i+1])
                {
                    S.erase (i, 2);                       
                    len = len-2;     
                }
            }
         //   cout<<"iteration"<<temp<<endl;
        }while(temp != len);
        return S;
    }
}