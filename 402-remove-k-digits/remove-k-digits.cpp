class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char> st;
        string ans = "";

        for (int i = 0; i < n; i++) {
            while (!st.empty() && k > 0 && st.top() > num[i]) {
                st.pop();
                k = k - 1;
            }

            st.push(num[i]);
        }

        while (!st.empty() && k > 0) {
            st.pop();
            k = k - 1;
        }

        if (st.empty()) {
            return "0";
        }

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        while (ans.size() > 0 && ans.back() == '0') {
            ans.pop_back();
        }

        if (ans.size() == 0) {
            return "0";
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};