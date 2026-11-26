class Solution {
public:
    bool canAliceWin(int n) {
        int move = 10;
        bool alice = true;
        while (n >= move) {
            n -= move;
            move--;
            alice = !alice;
        }
        return !alice;
    }
};