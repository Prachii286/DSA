class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        vector<int> ans;
        map<int, int> mpp;

        while (j < n) {
            if (nums[j] < 0) {
                mpp[nums[j]]++;
            }

            if (j - i + 1 < k) {
                j++;
            } else if (j - i + 1 == k) {
                int cnt = 0;
                int beauty = 0;

                for (auto it : mpp) {
                    cnt += it.second;

                    if (cnt >= x) {
                        beauty = it.first;
                        break;
                    }
                }

                ans.push_back(beauty);

                if (nums[i] < 0) {
                    mpp[nums[i]]--;
                }

                if (mpp[nums[i]] == 0) {
                    mpp.erase(nums[i]);
                }

                i++;
                j++;
            }
        }
        return ans;
    }
};
