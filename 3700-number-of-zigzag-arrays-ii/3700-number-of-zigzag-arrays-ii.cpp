class Solution {
public:
    const int MOD = 1e9 + 7;
    int sz;
    typedef vector<vector<long long>> Matrix;

    Matrix multiply(const Matrix& mat_a, const Matrix& mat_b) {
        Matrix mat_c(sz, vector<long long>(sz, 0));
        for (int i = 0; i < sz; i++)
            for (int k = 0; k < sz; k++) {
                if (!mat_a[i][k]) continue;
                for (int j = 0; j < sz; j++)
                    mat_c[i][j] = (mat_c[i][j] + mat_a[i][k] * mat_b[k][j]) % MOD;
            }
        return mat_c;
    }

    Matrix matpow(Matrix mat_m, long long pow_p) {
        Matrix mat_result(sz, vector<long long>(sz, 0));
        for (int i = 0; i < sz; i++) mat_result[i][i] = 1;
        while (pow_p > 0) {
            if (pow_p & 1) mat_result = multiply(mat_result, mat_m);
            mat_m = multiply(mat_m, mat_m);
            pow_p >>= 1;
        }
        return mat_result;
    }

    int zigZagArrays(int n, int l, int r) {
        int num_vals = r - l + 1;
        sz = num_vals * 2;

        Matrix mat_trans(sz, vector<long long>(sz, 0));

        for (int val_v = 0; val_v < num_vals; val_v++) {
            for (int dir_d = 0; dir_d < 2; dir_d++) {
                int idx_from = val_v * 2 + dir_d;
                if (dir_d == 0) {
                    for (int val_u = 0; val_u < val_v; val_u++)
                        mat_trans[val_u * 2 + 1][idx_from]++;
                } else {
                    for (int val_u = val_v + 1; val_u < num_vals; val_u++)
                        mat_trans[val_u * 2 + 0][idx_from]++;
                }
            }
        }

        vector<long long> vec_state(sz, 0);
        for (int val_prev = 0; val_prev < num_vals; val_prev++)
            for (int val_cur = 0; val_cur < num_vals; val_cur++) {
                if (val_prev == val_cur) continue;
                int dir_cur = (val_prev < val_cur) ? 0 : 1;
                vec_state[val_cur * 2 + dir_cur]++;
            }

        Matrix mat_pow = matpow(mat_trans, n - 2);
        vector<long long> vec_newstate(sz, 0);
        for (int i = 0; i < sz; i++)
            for (int j = 0; j < sz; j++)
                vec_newstate[i] = (vec_newstate[i] + mat_pow[i][j] * vec_state[j]) % MOD;

        long long num_ans = 0;
        for (int val_x : vec_newstate) num_ans = (num_ans + val_x) % MOD;
        return num_ans;
    }
};