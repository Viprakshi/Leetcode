class Solution {
public:
    int longestBalanced(string s) {
        string x = s;
        int n = x.length();
        int max_len = 0;
        for (int i = 0; i < n; i++) {
            int counts[26] = {0};
            int distinct_count = 0;
            for (int j = i; j < n; j++) {
                int char_idx = x[j] - 'a';
                if (counts[char_idx] == 0) {
                    distinct_count++;
                }
                counts[char_idx]++;
                int current_len = j - i + 1;
                if (current_len % distinct_count == 0) {
                    int target = current_len / distinct_count;
                    bool balanced = true;
                    for (int k = 0; k < 26; k++) {
                        if (counts[k] > 0 && counts[k] != target) {
                            balanced = false;
                            break;
                        }
                    }
                    if (balanced) {
                        max_len = max(max_len, current_len);
                    }
                }
            }
        }
        return max_len;
    }
};