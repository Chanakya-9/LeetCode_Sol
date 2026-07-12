class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> so = arr;
        sort(so.begin(), so.end());
        int n = so.size();

        unordered_map<int, int> mp;

        int count = 1;
        for (int i = 0; i < n; i++) {
            if(!mp.count(so[i])){

            mp[so[i]] = count++;
            }
        }

        for (int i = 0; i < n; i++) {
            arr[i] = mp[arr[i]];
        }

        return arr;
    }
};