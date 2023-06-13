class Solution{
public:
    vector<string> createstring(int num)
    {
        if(num ==1)
        {
            vector<string> one;
            one.push_back("0");
            one.push_back("1");
            return one;
        }
        vector<string> v_num(createstring(num-1)) ;
        vector<string> ans;
        for(auto it : v_num)
        {
            string s= '0' + it;
            ans.push_back(s);
        }
        
        for(auto it:v_num)
        {
            string s = '1' + it;
            if(s[1]!='1') ans.push_back(s);
        }
        
       return ans;
    }
    void generateBinaryStrings(int num)
    {
        vector<string> v = createstring(num);
        for(auto it:v )
        {
            cout << it << " ";
        }
    }
};
