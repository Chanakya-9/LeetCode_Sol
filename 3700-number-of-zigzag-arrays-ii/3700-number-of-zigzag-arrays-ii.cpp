class Solution {
public:
    static const long long MOD = 1000000007LL;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(const Matrix& A, const Matrix& B) {
        int n = A.size();
        Matrix C(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;

                long long aik = A[i][k];

                for (int j = 0; j < n; j++) {
                    if (B[k][j] == 0) continue;

                    C[i][j] = (C[i][j] + aik * B[k][j]) % MOD;
                }
            }
        }

        return C;
    }

    Matrix power(Matrix base, long long exp) {
        int n = base.size();

        Matrix res(n, vector<long long>(n, 0));
        for (int i = 0; i < n; i++) res[i][i] = 1;

        while (exp) {
            if (exp & 1) res = multiply(res, base);
            base = multiply(base, base);
            exp >>= 1;
        }

        return res;
    }

    vector<long long> multiplyVec(
        const Matrix& A,
        const vector<long long>& v
    ) {
        int n = A.size();
        vector<long long> res(n, 0);

        for (int i = 0; i < n; i++) {
            long long cur = 0;

            for (int j = 0; j < n; j++) {
                if (A[i][j] == 0) continue;

                cur = (cur + A[i][j] * v[j]) % MOD;
            }

            res[i] = cur;
        }

        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        int S = 2 * m;

        Matrix T(S, vector<long long>(S, 0));

        // state:
        // 0..m-1      => up
        // m..2m-1     => down

        for (int v = 0; v < m; v++) {

            // up[v] <- down[u], u < v
            for (int u = 0; u < v; u++) {
                T[v][m + u] = 1;
            }

            // down[v] <- up[u], u > v
            for (int u = v + 1; u < m; u++) {
                T[m + v][u] = 1;
            }
        }

        vector<long long> base(S, 0);

        // length = 2
        for (int v = 0; v < m; v++) {
            base[v] = v;           // up[v]
            base[m + v] = m - 1 - v; // down[v]
        }

        Matrix P = power(T, n - 2);

        vector<long long> finalState = multiplyVec(P, base);

        long long ans = 0;
        for (long long x : finalState) {
            ans = (ans + x) % MOD;
        }

        return (int)ans;
    }
};