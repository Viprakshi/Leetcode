class Solution {
public:
    string reverseWords(string s) {
        string word="";
        stack<string> st;
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                if(word!="") st.push(word);  
                word="";
            }
            else{
                word+=s[i];
            }
        }
        if(word!="")
        st.push(word);
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
            if(!st.empty()) ans+=" ";
            
        }
    return ans;

    }
};