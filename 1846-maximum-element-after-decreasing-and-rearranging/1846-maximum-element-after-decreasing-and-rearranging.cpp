// class Solution {
// public:
//     int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
//         int n = arr.size();
//         sort(arr.begin(), arr.end());
//         arr[0] = 1;
//         for (int i = 1; i < n; i++) {
//             if (arr[i] > arr[i - 1]) {
//                 arr[i] = arr[i - 1] + 1;
//             }
//         }

//         return arr[n - 1];
//     }
// };

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        vector<int> freq(n + 1,0);
        for(int i =0;i<n;i++){
            freq[min(arr[i],n)]++;
        }
        int ans = 0;
        for(int i =1;i<=n;i++){
            if(freq[i] == 0) continue;

            ans = min(ans + freq[i],i);
        }
        return ans;
    }
};