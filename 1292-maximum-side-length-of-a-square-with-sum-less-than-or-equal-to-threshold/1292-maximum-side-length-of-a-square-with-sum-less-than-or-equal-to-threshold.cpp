class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> ps(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ps[i + 1][j + 1] = mat[i][j]
                                + ps[i][j + 1]
                                + ps[i + 1][j]
                                - ps[i][j];
            }
        }

        for (int k = min(m, n); k >= 1; k--) {
            for (int i = 0; i + k <= m; i++) {
                for (int j = 0; j + k <= n; j++) {

                    int sum = ps[i + k][j + k]
                            - ps[i][j + k]
                            - ps[i + k][j]
                            + ps[i][j];

                    if (sum <= threshold)
                        return k;
                }
            }
        }
        return 0;
    }
};
