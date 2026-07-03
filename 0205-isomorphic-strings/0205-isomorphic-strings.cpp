class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char, char> st, ts;
        for(int i=0;i<s.size();i++){
            st[s[i]]=t[i];
            ts[t[i]]=s[i];
        }
        for(int i=0;i<s.size();i++){
            if(st[s[i]]!=t[i] || ts[t[i]]!=s[i])
            return false;
        }
        return true;
    }

};