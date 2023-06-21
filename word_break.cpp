class Solution
{
public:
    bool takenottake(string A, vector<string> &B)
    {
        if(A.size() == 0) return true;

        for(int i=0 ; i<B.size() ; i++)
        {
            if(A.find(B[i]) == 0)
            {
                string copy = A;
                A.erase(0 , B[i].length());
                if( takenottake(A,B) ) return true ;
                A = copy;
            }
        }
        return false;
    }
    int wordBreak(string A, vector<string> &B) 
    {
        if(takenottake(A,B)) return 1;
        return 0;
    }
};
