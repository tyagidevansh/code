class Solution {
public:
    void calcSubset(vector<int>& nums, vector<vector<int>>& res, 
                    vector<int>& subset, int index) {
            
            res.push_back(subset);

            for (int i = index; i < nums.size(); i++) {
                subset.push_back(nums[i]);
                calcSubset(nums, res, subset, i + 1);
                subset.pop_back();
            }
        }

    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        calcSubset(nums, res, subset, 0);

        int sum = 0;
        vector<int> xorArray(res.size());

        for (int i = 0; i < res.size(); i++) {
            xorArray[i] = 0;
            for (int j = 0; j < res[i].size(); j++) {
                xorArray[i] ^= res[i][j];
            }
            sum += xorArray[i];
        }

        return sum;

    }
};