class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int right=0, left=0, ans=0;
        while(left<g.size() && right<s.size()){
            if(g[left]<=s[right]){
                ans++;
                left++;
               
            }
            right++;

        }
        return ans;
    }
};