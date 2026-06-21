class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans="";
        stack<int> st;
        for(int i=0;i<num.size();i++){
            if(st.empty()){
                st.push(num[i]);
                continue;
            } 
            else if(st.top()>num[i]){
                while(!st.empty() && k>0 && st.top()>num[i])
                {
                    st.pop();
                    k--;
                }
                
            }
            st.push(num[i]);
            
        }
        while(k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        int i = 0;
        while(i < ans.size()-1 && ans[i] == '0')
            i++;

        ans = ans.substr(i);
        if(ans.empty()) return "0";
        return ans;
    }
};