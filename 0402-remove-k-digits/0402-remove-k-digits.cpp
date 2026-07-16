class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        st.push(num[0]);
        for(int i=1;i<num.size();i++){
            while(!st.empty() && st.top()>num[i] && k>0){
                st.pop();
                k--;
            }
            st.push(num[i]);            
        }
        while(k>0){
            st.pop();
            k--;
        }
        string ans = "";
while(!st.empty()){
    ans.push_back(st.top());
    st.pop();
}
reverse(ans.begin(), ans.end());
        if(ans=="") return "0";
        long long x=0;
        while(ans[x]=='0' && x<ans.size()-1) x++;
        ans = ans.substr(x);
        if(ans=="") return "0";
        return ans;
    }
};