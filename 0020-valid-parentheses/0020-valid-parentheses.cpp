class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        if(s.length()<=1) return false;
        st.push('o');
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[') st.push(s[i]);
            else{
                char x=st.top();
                if(s[i]==')' && x!='(') return false;
                if(s[i]=='}' && x!='{') return false;
                if(s[i]==']' && x!='[') return false;
                else{
                    st.pop();
                }
            }
        }
        if(st.top()=='o') return true;
        else return false;
    }    
};