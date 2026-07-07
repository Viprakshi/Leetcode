class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mpp;
        int i=0,j=0, ans=0;
        while(j<s.length()){
            if(mpp[s[j]]!=0){
                while(mpp[s[j]]!=0){
                    mpp[s[i]]--;
                    i++;
                }
            }
            else{
                ans=max(ans, j-i+1);
                mpp[s[j]]++;
                j++;
            }
        }
        return ans;
    }
};