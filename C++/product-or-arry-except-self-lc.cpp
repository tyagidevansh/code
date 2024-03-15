class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int pre = 1, post = 1;
        vector<int> res;

        for (int i = 0; i < nums.size(); i++) {
            res.push_back(pre);
            pre *= nums[i];
        }

        for (int i = nums.size() - 1; i >= 0; i--) {
            res[i] *= post;
            post *= nums[i];
        }
        return res;
    }
};