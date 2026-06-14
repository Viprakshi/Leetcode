class Solution {
public:
    void generate(string temp,vector<string>& ans,string digits,int pos,vector<string>mp){
        if(pos>=digits.length()){
            ans.push_back(temp);
            return;
        }
        int d=digits[pos]-'0'; //2
        
            for(char ch:mp[d]){
                
                generate(temp+ch,ans,digits,pos+1,mp);
            }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        vector<string> mp = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        generate("",ans,digits,0,mp);
        return ans;
    }
};