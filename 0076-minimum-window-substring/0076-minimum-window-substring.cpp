class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mpp;

        for(char ch : t)
            mpp[ch]++;

        int left = 0, right = 0;
        int count = 0;

        int start = -1;
        int min_len = INT_MAX;

        while(right < s.length()) {

            if(mpp[s[right]] > 0)
                count++;

            mpp[s[right]]--;
            right++;

            while(count == t.length()) {

                if(right - left < min_len) {
                    min_len = right - left;
                    start = left;
                }

                mpp[s[left]]++;

                if(mpp[s[left]] > 0)
                    count--;

                left++;
            }
        }

        return start == -1 ? "" : s.substr(start, min_len);
    }
};