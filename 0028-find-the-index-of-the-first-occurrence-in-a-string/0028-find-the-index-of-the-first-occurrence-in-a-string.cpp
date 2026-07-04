class Solution {
public:
    int strStr(string h, string n) {
        int hn = h.size(), nn = n.size();
        for (int i = 0; i <= hn - nn; i++) {
            if (h.substr(i, nn) == n) {
                return i;
            }
        }
        return -1;
    }
};