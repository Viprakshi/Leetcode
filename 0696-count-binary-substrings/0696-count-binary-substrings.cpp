class Solution {
public:
    int countBinarySubstrings(string s) {
        int current_index = 0;
        int string_length = s.size();
        vector<int> group_sizes;
        
        while (current_index < string_length) {
            int group_count = 1;
            
            while (current_index + 1 < string_length &&
                   s[current_index + 1] == s[current_index]) {
                ++group_count;
                ++current_index;
            }
            
            group_sizes.push_back(group_count);
            ++current_index;
        }
        
        int result = 0;
        
        for (int i = 1; i < group_sizes.size(); ++i) {
            result += min(group_sizes[i - 1], group_sizes[i]);
        }
        
        return result;
    }
};