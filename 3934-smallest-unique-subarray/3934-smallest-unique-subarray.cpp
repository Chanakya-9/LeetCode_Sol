class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> s = nums;
        s.push_back(0);
        int N = n + 1;
        int alpha = max(N, *max_element(s.begin(), s.end()) + 1);

        vector<int> p(N), c(N), cnt(alpha, 0);
        for (int i = 0; i < N; i++) cnt[s[i]]++;
        for (int i = 1; i < alpha; i++) cnt[i] += cnt[i - 1];
        for (int i = 0; i < N; i++) p[--cnt[s[i]]] = i;

        c[p[0]] = 0;
        int classes = 1;
        for (int i = 1; i < N; i++) {
            if (s[p[i]] != s[p[i - 1]]) classes++;
            c[p[i]] = classes - 1;
        }

        vector<int> pn(N), cn(N);
        for (int h = 0; (1 << h) < N; ++h) {
            for (int i = 0; i < N; i++) {
                pn[i] = p[i] - (1 << h);
                if (pn[i] < 0) pn[i] += N;
            }
            fill(cnt.begin(), cnt.begin() + classes, 0);
            for (int i = 0; i < N; i++) cnt[c[pn[i]]]++;
            for (int i = 1; i < classes; i++) cnt[i] += cnt[i - 1];
            for (int i = N - 1; i >= 0; i--) p[--cnt[c[pn[i]]]] = pn[i];

            cn[p[0]] = 0;
            classes = 1;
            for (int i = 1; i < N; i++) {
                pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % N]};
                pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << h)) % N]};
                if (cur != prev) ++classes;
                cn[p[i]] = classes - 1;
            }
            c.swap(cn);
            if (classes == N) break;
        }

        vector<int> rank(N, 0);
        for (int i = 0; i < N; i++) rank[p[i]] = i;

        int k = 0;
        vector<int> lcp(N - 1, 0);
        for (int i = 0; i < N; i++) {
            if (rank[i] == N - 1) {
                k = 0;
                continue;
            }
            int j = p[rank[i] + 1];
            while (i + k < N && j + k < N && s[i + k] == s[j + k]) k++;
            lcp[rank[i]] = k;
            if (k) k--;
        }

        int ans = n;
        for (int i = 1; i < N; i++) {
            int m = max(i > 1 ? lcp[i - 1] : 0, i < N - 1 ? lcp[i] : 0);
            if (p[i] + m + 1 <= n) {
                ans = min(ans, m + 1);
            }
        }

        return ans;
    }
};