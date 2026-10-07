class Solution {
private:
    std::vector<std::string> result;
    bool isValid(const std::string& str) {
        int count = 0;
        for (char ch : str) {
            if (ch == '(') {
                count++;
            } else if (ch == ')') {
                count--;
                if (count < 0) return false;
            }
        }
        return count == 0;
    }
    void dfs(int index, int leftRem, int rightRem, const std::string& s, std::string path) {
        
        if (leftRem == 0 && rightRem == 0) {
            std::string candidate = path + s.substr(index);
            if (isValid(candidate)) {
                result.push_back(candidate);
            }
            return;
        }
        for (int i = index; i < s.length(); ++i) {
            
            if (i > index && s[i] == s[i - 1]) {
                path.push_back(s[i]);
                continue;
            }
            char ch = s[i];
            
            if (rightRem > 0 && ch == ')') {
                dfs(i + 1, leftRem, rightRem - 1, s, path);
            }
            
            else if (leftRem > 0 && ch == '(') {
                dfs(i + 1, leftRem - 1, rightRem, s, path);
            }
            
            path.push_back(ch);
        }
    }
public:
    std::vector<std::string> removeInvalidParentheses(std::string s) {
        result.clear();
        int leftRem = 0, rightRem = 0;
        
        for (char ch : s) {
            if (ch == '(') {
                leftRem++;
            } else if (ch == ')') {
                if (leftRem > 0) {
                    leftRem--;
                } else {
                    rightRem++;
                }
            }
        }
    
        dfs(0, leftRem, rightRem, s, "");
        return result;
    }
};