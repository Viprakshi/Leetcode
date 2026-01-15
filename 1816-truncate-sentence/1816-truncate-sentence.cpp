class Solution {
public:
    string truncateSentence(string s, int k) {
        string res;
        for (char c : s) {
            if (c == ' ') k--;
            if (k == 0) break;
            res += c;
        }
        return res;
    }
};
