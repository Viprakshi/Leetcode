class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";

    for (int i = 0; i < s.length(); i++) {
        int start = i, end = i;
        while (start >= 0 && end < s.length() && s[start] == s[end]) {
            start--;
            end++;
        }
        if (end - start - 1 > ans.length()) {
            ans = s.substr(start + 1, end - start - 1);
        }

        start = i, end = i + 1;
        while (start >= 0 && end < s.length() && s[start] == s[end]) {
            start--;
            end++;
        }
        if (end - start - 1 > ans.length()) {
            ans = s.substr(start + 1, end - start - 1);
        }
    }

    return ans;
    }
};