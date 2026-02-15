class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        int index_a = a.size() - 1;
        int index_b = b.size() - 1;
        int carry = 0;

        while (index_a >= 0 || index_b >= 0 || carry > 0) {
            if (index_a >= 0) {
                carry += a[index_a] - '0';
                index_a--;
            }

            if (index_b >= 0) {
                carry += b[index_b] - '0';
                index_b--;
            }

            result.push_back((carry % 2) + '0');
            carry /= 2;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
