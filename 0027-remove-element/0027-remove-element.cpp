class Solution {
public:
    int removeElement(vector<int>& n, int v) {
        int j = 0;
        for (int i = 0; i < n.size(); i++) {
            if (n[i] != v) {
                n[j] = n[i];
                j++;
            }
        }
        return j;
    }
};