class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> x_y;
        unordered_map<char, char> y_x;
        if(s.length()!=t.length()) return false;
        for(int i=0;i<s.length();i++){
            x_y[s[i]]=t[i];
            y_x[t[i]]=s[i];
        }
        for(int i=0;i<s.length();i++){
            if(x_y[s[i]]!=t[i] || y_x[t[i]]!=s[i]) return false;
        }
        return true;
    }
};