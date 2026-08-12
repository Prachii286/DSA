class Solution {
public:
    vector<int> nextSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, n);
        stack<pair<int, int>> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top().first >= nums[i]) {
                st.pop();
            }

            if (!st.empty()) {
                ans[i] = st.top().second;
            }

            st.push({nums[i], i});
        }
        return ans;
    }

    vector<int> prevSmallerEqual(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<pair<int, int>> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top().first > nums[i]) {
                st.pop();
            }

            if (!st.empty()) {
                ans[i] = st.top().second;
            }

            st.push({nums[i], i});
        }
        return ans;
    }

    vector<int> nextGreater(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, n);
        stack<pair<int, int>> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top().first <= nums[i]) {
                st.pop();
            }

            if (!st.empty()) {
                ans[i] = st.top().second;
            }

            st.push({nums[i], i});
        }
        return ans;
    }

    vector<int> prevGreaterEqual(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<pair<int, int>> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top().first < nums[i]) {
                st.pop();
            }

            if (!st.empty()) {
                ans[i] = st.top().second;
            }

            st.push({nums[i], i});
        }
        return ans;
    }

    long long subarrayMinSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> nse = nextSmaller(nums);
        vector<int> psee = prevSmallerEqual(nums);
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            int left = i - psee[i];
            int right = nse[i] - i;

            long long val = 1LL * left * right * nums[i];
            sum = sum + val;
        }
        return sum;
    }

    long long subarrayMaxSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge = nextGreater(nums);
        vector<int> pgee = prevGreaterEqual(nums);
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            int left = i - pgee[i];
            int right = nge[i] - i;

            long long val = 1LL * left * right * nums[i];
            sum = sum + val;
        }
        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        return subarrayMaxSum(nums) - subarrayMinSum(nums);
    }
};