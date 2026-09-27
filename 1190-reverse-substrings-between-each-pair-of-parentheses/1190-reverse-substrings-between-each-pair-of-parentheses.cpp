class Solution {
    string str;

    string change(string x) {
        string ans = "";
        for (int i = x.size() - 1; i >= 0; i--) {
            ans += x[i];
        }
        return ans;
    }

    string rev(int &i) {
        string ans = "";

        while (i < str.size() && str[i] != ')') {

            if (str[i] == '(') {
                i++;
                string temp = rev(i);
                i++;
                ans += change(temp);
            }
            else {
                ans += str[i];
                i++;
            }
        }

        return ans;
    }

public:
    string reverseParentheses(string s) {
        str = s;
        int i = 0;
        return rev(i);
    }
};