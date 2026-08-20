class Solution {
public:

    void permutation(int index, vector<int> &nums, vector<vector<int>> &temp){
        if(index==nums.size()){
            temp.push_back(nums);
            return;
        }
        unordered_set<int> used;

        for(int i=index;i<nums.size();i++){
            if(used.count(nums[i]))
                continue;

            used.insert(nums[i]);
            swap(nums[i],nums[index]);
            permutation(index+1,nums,temp);
            swap(nums[i],nums[index]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> temp;
        permutation(0,nums,temp);
        return temp;
    }
};