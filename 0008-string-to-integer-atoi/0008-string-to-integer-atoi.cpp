class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0;
        int sign = 0;
        int i = 0;

        // Skip leading spaces
        while (i < s.length() && s[i] == ' ')
            i++;

        // Check if string ended
        if (i == s.length())
            return 0;

        // Optional sign
        if (s[i] == '+') {
            i++;
        } else if (s[i] == '-') {
            sign = 1;
            i++;
        }

        // Read digits
        while (i < s.length() && isdigit(s[i])) {
            ans = ans * 10 + (s[i] - '0');

            // Positive overflow
            if (sign == 0 && ans >= INT_MAX)
                return INT_MAX;

            // Negative overflow
            if (sign == 1 && ans > (long long)INT_MAX + 1)
                return INT_MIN;

            i++;
        }

        if (sign)
            return -ans;

        return ans;
    }
};