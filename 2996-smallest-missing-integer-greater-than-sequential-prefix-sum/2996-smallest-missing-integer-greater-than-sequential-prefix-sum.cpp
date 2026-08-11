class Solution {
public:
    int missingInteger(vector<int>& a) {
        int s = a[0];
        
        for (int i = 1; i < a.size(); ++i) {
            if (a[i] == a[i - 1] + 1) s += a[i];
            else break;
        }
        
        unordered_set<int> st(a.begin(), a.end());
        while (st.count(s)) s++;
        
        return s;
    }
};