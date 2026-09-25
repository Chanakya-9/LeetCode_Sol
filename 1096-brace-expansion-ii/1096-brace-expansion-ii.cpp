class Solution {
    set<string> parse(string& s, int& i) {
        set<string> res = {""};

        while (i < s.size() && s[i] != '}' && s[i] != ',') {
            set<string> cur;
            if (s[i] == '{') {
                i++;
                while (true) {
                    set<string> sub = parse(s, i);
                    cur.insert(sub.begin(), sub.end());
                    if (s[i] == '}') {
                        i++;
                        break;
                    }
                    i++;
                }
            } else {
                string word = "";
                while (i < s.size() && isalpha(s[i])) {
                    word += s[i++];
                }
                cur.insert(word);
            }

            set<string> nxt;
            for (const string& a : res) {
                for (const string& b : cur) {
                    nxt.insert(a + b);
                }
            }
            res = move(nxt);
        }

        return res;
    }

public:
    vector<string> braceExpansionII(string expression) {
        int i = 0;
        set<string> st = parse(expression, i);
        return vector<string>(st.begin(), st.end());
    }
};