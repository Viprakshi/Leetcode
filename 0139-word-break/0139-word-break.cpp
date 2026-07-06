class Solution {
public:
    bool valid(string x, vector<string>& dict){
        for(string word:dict){
            if(word==x) return true;
        }
        return false;
    }
    bool generate(string s, vector<string>& dict, int curr,vector<int>& dp){

        if(curr==s.length()) return true;
        if(dp[curr]!=-1) return dp[curr];
        for(int i=curr;i<s.size();i++){
            string x=s.substr(curr, i-curr+1);
            if(valid(x,dict) && generate(s,dict,i+1,dp)){
                return dp[curr]=true;
            }
            
        }
        return dp[curr]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.length(),-1);
        return generate(s, wordDict, 0,dp);
    }
};