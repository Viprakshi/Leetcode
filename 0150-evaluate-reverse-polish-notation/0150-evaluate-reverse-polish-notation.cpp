class Solution {
public:
    int op(int y, int x, char c){
        if(c=='+') return y+x;
        if(c=='-') return y-x;
        if(c=='*') return y*x;
        return y/x;
    }
    int evalRPN(vector<string>& s) {
        //postfix-->infix
        stack<int> st;
        for(int i=0;i<s.size();i++){
            if(s[i]!="+" && s[i]!="-" && s[i]!="*" && s[i]!="/"){
                st.push(stoi(s[i]));
            }
            else{
                int x=st.top();
                st.pop();
                int y=st.top();
                st.pop();
                st.push(op(y,x,s[i][0]));
            }
        }
        return st.top();
    }
};