class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> maxPrefix(n);
        vector<int> minSuffix(n);

        maxPrefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            maxPrefix[i] = max(maxPrefix[i - 1], nums[i]);
        }

        minSuffix[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            minSuffix[i] = min(minSuffix[i + 1], nums[i]);
        }

        for (int i = 0; i < n; i++) {
            int score = maxPrefix[i] - minSuffix[i];

            if (score <= k) {
                return i;
            }
        }

        return -1;
    }
};