class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> rightSum(n,0);
        vector<int> leftSum(n,0);

        int right = accumulate(nums.begin(),nums.end(),0);
        int left = 0;

        for(int i=0;i<n;i++){
            right=right-nums[i];
            rightSum[i]=right;
            

            leftSum[i]=left;
            left=left+nums[i];
        }

        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            ans[i] = abs(leftSum[i]-rightSum[i]);
        }
        return ans;
    }
};