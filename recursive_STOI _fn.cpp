class Solution{
  public:
    /*You are required to complete this method */
    int pos(string s, int index)
    {
        if(index == s.size()) return 0;
        if(s[index]<48 || s[index]>57) return -1;
        
        
        int count = s[index]-48;
        int position = pow(10,s.size()-1-index);
        count = count * position;
        index++;
        if(pos(s,index) == -1) return -1;
        count = count + pos(s,index);
        return count;
    }
    int atoi(string str) {
        //ascii of 0 is 48 and that of 9 is 57
        int sign = 1;
        if(str[0]=='-') 
        {
            sign = -1;
            str.erase(0,1);
        }
        
        int ans = pos(str,0);
        if(ans == -1) return -1;
        return ans*sign;
        
    }
};
