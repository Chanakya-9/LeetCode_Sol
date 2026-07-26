class Solution {
public:
    unordered_map<int, int> par;

    int find(int x) {
        if (!par.count(x)) {
            par[x] = x;
        }

        if (par[x] == x) {
            return x;
        }

        return par[x] = find(par[x]);
    }

    void uni(int a, int b) {
        a = find(a);
        b = find(b);

        if (a != b) {
            par[a] = b;
        }
    }

    int removeStones(vector<vector<int>>& stones) {

        for (auto &s : stones) {
            uni(s[0], s[1] + 10001);
        }

        unordered_set<int> comp;

        for (auto &s : stones) {
            comp.insert(find(s[0]));
        }

        return stones.size() - comp.size();
    }
};