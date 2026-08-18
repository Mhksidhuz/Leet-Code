class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        int n = nums.size();

        for(auto it : nums){
            mpp[it]++;
        }
        if(k == n){
         return *max_element(nums.begin(), nums.end());
        }

        if(k==1){
            int maxi = -1;
            for(int i=0;i<n;i++){
                if(mpp[nums[i]]==1){
                    maxi = max(maxi,nums[i]);
                }
            }
            return maxi;
        }

        int ans = -1;

        if (mpp[nums[0]] == 1) {
            ans = max(ans, nums[0]);
        }

        if (mpp[nums[n - 1]] == 1) {
            ans = max(ans, nums[n - 1]);
        }

        return ans;
    }
};