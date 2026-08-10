class Solution {
public:
    int mod = 1e9 + 7;

    /* Function to find the indices of next smaller elements */
    vector<int> nextSmallerIndex(vector<int>& arr) {
        int n = arr.size();
        stack<pair<int, int>> st;
        vector<int> ans(n, n);

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top().first >= arr[i]) {
                st.pop();
            }

            if (!st.empty() && st.top().first < arr[i]) {
                ans[i] = st.top().second;
            }

            st.push({arr[i], i});
        }
        return ans;
    }

    /* Function to find the indices of previous smaller or equal elements */
    vector<int> prevSmallerIndex(vector<int>& arr) {
        int n = arr.size();
        stack<pair<int, int>> st;
        vector<int> ans(n, -1);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top().first > arr[i]) {
                st.pop();
            }

            if (!st.empty()) {
                ans[i] = st.top().second;
            }

            st.push({arr[i], i});
        }
        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;

        vector<int> nse = nextSmallerIndex(arr);
        vector<int> pse = prevSmallerIndex(arr);

        for (int i = 0; i < n; i++) {
            int left = i - pse[i];
            int right = nse[i] - i;

            int val = (1LL * left * right * arr[i]) % mod;
            sum = sum + val;
            sum = sum % mod;
        }
        return sum;
    }
};