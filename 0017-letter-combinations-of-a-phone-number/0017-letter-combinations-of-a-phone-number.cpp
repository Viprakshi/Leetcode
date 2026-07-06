class Solution {
public:
    void generate(string temp,vector<string>& ans,string digits,int pos,vector<string>mp){
        if(pos==digits.size()){
            ans.push_back(temp);
            return;
        }
        for(char x:mp[digits[pos]-'0']){
            generate(temp+x,ans,digits,pos+1,mp);
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