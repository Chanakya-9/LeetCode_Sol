class Solution {
public:
    bool checkOverlap(int r, int xc, int yc, int x1, int y1, int x2, int y2) {
        int dx = xc < x1 ? x1 - xc : (xc > x2 ? xc - x2 : 0);
        int dy = yc < y1 ? y1 - yc : (yc > y2 ? yc - y2 : 0);
        return dx * dx + dy * dy <= r * r;
    }
};
