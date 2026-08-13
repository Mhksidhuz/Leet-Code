class Solution {
public:

    void recursion(int index,vector<int> &nums,vector<int> &ans,vector<vector<int>> &temp){

        if(index>=nums.size()){
            temp.push_back(ans);
            return;
        }
        ans.push_back(nums[index]);
        recursion(index+1,nums,ans,temp);

        ans.pop_back();
        recursion(index+1,nums,ans,temp);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> temp;
        vector<int> ans;
        recursion(0,nums,ans,temp);

        return temp;
    }
};