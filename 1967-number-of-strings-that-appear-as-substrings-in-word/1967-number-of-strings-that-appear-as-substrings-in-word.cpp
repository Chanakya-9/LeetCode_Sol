// class Solution {
// public:
//     int numOfStrings(vector<string>& patterns, string word) {

//         unordered_set<string> sub;
//         int n =word.size();

//         for (int i = 0; i < n; i++) {
//             for (int j = 1; j <= n - i; j++) {

//                 sub.insert(word.substr(i, j));
//             }
//         }

//         int ans=0;
//         for(auto x:patterns){
//             if(sub.count(x)){
//                 ans++;
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;

        for (auto &p : patterns) {
            if (word.find(p) != string::npos)
                ans++;
        }

        return ans;
    }
};