class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i=0;i<asteroids.size();i++){
            if(!st.empty() && st.top()>0 && asteroids[i]<0){
                while(!st.empty() && st.top()<-1*asteroids[i] && st.top()>0 && asteroids[i]<0)
                st.pop();
                if(!st.empty() && st.top()>-1*asteroids[i])
                    continue;
                else if(!st.empty() && st.top()==-1*asteroids[i]){
                    st.pop();
                }
                else{
                    st.push(asteroids[i]);
                }
                
            }
            else
                st.push(asteroids[i]);            
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};