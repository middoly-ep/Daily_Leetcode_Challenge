#include <vector>

using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<int>> multiply(vector<vector<int>> &A, vector<vector<int>> &B){
        int m = A.size();
        vector<vector<int>> res(m, vector<int>(m, 0));
        for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++){
        for (int k = 0; k < m; k++){
            long long tmp = (1LL * A[i][k] * B[k][j]) % MOD;
            res[i][j] += tmp;
            res[i][j] %= MOD;
        }
        }
        }
        return res;
    }

    void exp(vector<vector<int>> &mat, int a){
        int m = mat.size();
        vector<vector<int>> res(m, vector<int>(m, 0));
        vector<vector<int>> base = mat;
        for (int i = 0; i < m; i++) res[i][i] = 1;
        while (a > 0){
            if (a % 2 == 1) res = multiply(res, base);
            base = multiply(base, base);
            a /= 2;
        }
        mat = res;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        if (n == 1) return m;
        n--;

        vector<vector<int>> mat(2 * m, vector<int>(2 * m, 0));
        // Góc trên phải: TĂNG (cần prev < curr)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < i; j++) {
                mat[i][j + m] = 1;
            }
        }

        // Góc dưới trái: GIẢM (cần prev > curr)
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                mat[i + m][j] = 1;
            }
        }

        exp(mat, n);
        int res = 0;
        for (int i = 0; i < 2 * m; i++){
        for (int j = 0; j < 2 * m; j++){
            res += mat[i][j] % MOD;
            res %= MOD;
        }
        }
        return res;
    }
};
