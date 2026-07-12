class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(!arr.size()){
            return arr;
        }
        vector<int> so = arr;
        sort(so.begin(), so.end());

        unordered_map<int, int> mp;
        int rank = 1;

        mp[so[0]] = rank;
        for (int i = 1; i < so.size(); i++) {
            if (so[i] != so[i - 1])
                rank++;
            mp[so[i]] = rank;
        }

        for (int &x : arr)
            x = mp[x];

        return arr;
    }
};