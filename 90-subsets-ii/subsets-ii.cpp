class Solution {
public:
    void subset(int index,vector<int>&nums,vector<int> &ans,vector<vector<int>> &temp){

        temp.push_back(ans);

        for(int i=index;i<nums.size();i++){
            if(i>index && nums[i]==nums[i-1])continue;

            ans.push_back(nums[i]);
            subset(i+1,nums,ans,temp);
            ans.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        vector<vector<int>>temp;

        subset(0,nums,ans,temp);

        return temp;
    }
};