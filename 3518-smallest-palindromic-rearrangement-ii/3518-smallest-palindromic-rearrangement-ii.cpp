class Solution {
    long long nCr(int n, int r) {
        if (r > n - r) r = n - r;
        long long res = 1;
        for (int i = 1; i <= r; ++i) {
            res = res * (n - i + 1) / i;
            if (res > 2000000) res = 2000000;
        }
        return res;
    }

    long long countPerms(vector<int>& cnt) {
        long long res = 1;
        int rem = 0;
        for (int x : cnt) rem += x;
        
        for (int x : cnt) {
            if (x == 0) continue;
            res *= nCr(rem, x);
            if (res > 2000000) return 2000000;
            rem -= x;
        }
        return res;
    }

public:
    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        vector<int> half_cnt(26, 0);
        string mid = "";
        int len = 0;

        for (int i = 0; i < 26; ++i) {
            half_cnt[i] = freq[i] / 2;
            len += half_cnt[i];
            if (freq[i] % 2 != 0) {
                mid = string(1, i + 'a');
            }
        }

        if (countPerms(half_cnt) < k) return "";

        string half_str = "";
        
        for (int i = 0; i < len; ++i) {
            for (int c = 0; c < 26; ++c) {
                if (half_cnt[c] > 0) {
                    half_cnt[c]--;
                    long long perms = countPerms(half_cnt);
                    
                    if (k <= perms) {
                        half_str += (char)(c + 'a');
                        break;
                    } else {
                        k -= perms;
                        half_cnt[c]++;
                    }
                }
            }
        }

        string rev_half = half_str;
        reverse(rev_half.begin(), rev_half.end());
        return half_str + mid + rev_half;
    }
};