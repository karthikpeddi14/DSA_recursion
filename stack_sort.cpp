/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void correct_place(stack<int> &s , int ele)
{
    if(s.size()==0 or s.top()<= ele ) 
    {
        s.push(ele);
        return;
    }
    
    int x = s.top();
    s.pop();
    correct_place(s,ele);
    s.push(x);
}
void Sorter(stack<int> &s)
{
    if(s.size()==1) return;
    int x = s.top();
    s.pop();
    Sorter(s);
    correct_place(s,x);
}
void SortedStack :: sort()
{
   Sorter(s);
}
