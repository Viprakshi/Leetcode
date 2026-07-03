class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int depth=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                depth++;
                if(depth!=1) ans+=s[i];
            }
            else if(s[i]==')'){
                depth--;
                if(depth!=0) ans+=s[i];
            }
        }
        return ans;
    }
};