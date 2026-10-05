class Solution {
    string str;
    int score(int l, int r) {
        if (l + 1 == r) {
            return 1;
        }
        int o = 0;
        for (int i = l; i < r; i++) {
            if (str[i] == '(')
                o++;
            else
                o--;

            
            if (o == 0) {
                return score(l, i) + score(i + 1, r);
            }
        }

       
        return 2 * score(l + 1, r - 1);
    }

public:
    int scoreOfParentheses(string s) {
        str = s;
        return score(0, s.size() - 1);
    }
};