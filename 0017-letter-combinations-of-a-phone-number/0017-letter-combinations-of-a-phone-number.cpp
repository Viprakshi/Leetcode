class Solution {
public:
    vector<string> ans;

    void solve(int idx, string digits, string curr,
               vector<string>& mp) {

        if(idx == digits.size()) {
            ans.push_back(curr);
            return;
        }

        string letters = mp[digits[idx] - '0'];

        for(char ch : letters) {
            solve(idx + 1, digits, curr + ch, mp);
        }
    }

    vector<string> letterCombinations(string digits) {

        if(digits.empty()) return {};

        vector<string> mp = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        solve(0, digits, "", mp);

        return ans;
    }
};