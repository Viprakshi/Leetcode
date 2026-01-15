class Solution {
public:
    string sortSentence(string s) {
        vector<string> words(10);
        string cur;

        for (char c : s) {
            if (c == ' ') {
                int idx = cur.back() - '1';
                cur.pop_back();
                words[idx] = cur;
                cur.clear();
            } else cur += c;
        }

        int idx = cur.back() - '1';
        cur.pop_back();
        words[idx] = cur;

        string res;
        for (string w : words)
            if (!w.empty())
                res += w + " ";
        res.pop_back();
        return res;
    }
};
