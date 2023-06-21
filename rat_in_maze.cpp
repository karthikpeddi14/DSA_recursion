class Solution{
    public:
    void makepath(vector<string>& ans , string& per_sub ,vector<vector<int>> &m, int n , int r, int c)
    {
        if(r==n-1 && c == n-1)
        {
          if(m[r][r] == 1) ans.push_back(per_sub);
            return;
        }
        
        bool condition = r<0 || r>=n || c>=n || c<0;
        if(condition || m[r][c]==0) return;
        
        m[r][c] =0;
        per_sub.push_back('D');
        makepath(ans,per_sub,m,n,r+1,c);
        per_sub.pop_back();
        
        per_sub.push_back('U');
        makepath(ans,per_sub,m,n,r-1,c);
        per_sub.pop_back();
        
        per_sub.push_back('R');
        makepath(ans,per_sub,m,n,r,c+1);
        per_sub.pop_back();
        
        per_sub.push_back('L');
        makepath(ans,per_sub,m,n,r,c-1);
        per_sub.pop_back();
        
        m[r][c] = 1;
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) 
    {
        vector<string> ans;
        string per_sub;
        makepath(ans,per_sub,m,n,0,0);
        return ans;
    }
};
