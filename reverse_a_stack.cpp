class Solution{
public:
    void insertatbottom(stack<int> &st , int element)
    {
        if(st.empty())
        {
            st.push(element);
            return;
        }
        int topele = st.top();
        st.pop();
        insertatbottom(st,element);
        st.push(topele);
    }
    void Reverse(stack<int> &St)
    {
        if(St.empty()) return;
        int x = St.top();
        St.pop();
        Reverse(St);
        insertatbottom(St,x);
        
    }
};
