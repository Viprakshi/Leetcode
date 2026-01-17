class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft,
                                vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                long long x_left   = max(bottomLeft[i][0], bottomLeft[j][0]);
                long long y_bottom = max(bottomLeft[i][1], bottomLeft[j][1]);
                long long x_right  = min(topRight[i][0], topRight[j][0]);
                long long y_top    = min(topRight[i][1], topRight[j][1]);

                if (x_right > x_left && y_top > y_bottom) {
                    long long side = min(x_right - x_left, y_top - y_bottom);
                    ans = max(ans, side * side);
                }
            }
        }
        return ans;
    }
};
