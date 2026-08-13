struct Node {
    int mx = 0, pre = 0, suf = 0;
    char pc = ' ', sc = ' ';
};

class Solution {
    int n;
    string s;
    vector<Node> tree;

    Node merge(const Node& L, const Node& R, int lsz, int rsz) {
        Node res;
        res.pc = L.pc;
        res.sc = R.sc;
        res.mx = max(L.mx, R.mx);

        if (L.sc == R.pc) {
            res.mx = max(res.mx, L.suf + R.pre);
        }

        res.pre = L.pre;
        if (L.pre == lsz && L.pc == R.pc) {
            res.pre += R.pre;
        }

        res.suf = R.suf;
        if (R.suf == rsz && R.sc == L.sc) {
            res.suf += L.suf;
        }

        return res;
    }

    void build(int p, int l, int r) {
        if (l == r) {
            tree[p] = {1, 1, 1, s[l], s[l]};
            return;
        }
        int m = l + (r - l) / 2;
        build(2 * p, l, m);
        build(2 * p + 1, m + 1, r);
        tree[p] = merge(tree[2 * p], tree[2 * p + 1], m - l + 1, r - m);
    }

    void update(int p, int l, int r, int idx, char ch) {
        if (l == r) {
            s[idx] = ch;
            tree[p] = {1, 1, 1, ch, ch};
            return;
        }
        int m = l + (r - l) / 2;
        if (idx <= m) update(2 * p, l, m, idx, ch);
        else update(2 * p + 1, m + 1, r, idx, ch);
        tree[p] = merge(tree[2 * p], tree[2 * p + 1], m - l + 1, r - m);
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        this->s = s;
        n = s.length();
        tree.resize(4 * n);
        build(1, 0, n - 1);

        int q = queryIndices.size();
        vector<int> ans(q);

        for (int i = 0; i < q; i++) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            ans[i] = tree[1].mx;
        }

        return ans;
    }
};