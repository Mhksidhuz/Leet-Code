class Solution {
public:

    void permutation(vector<int> &nums,vector<int> &freq,vector<int> &ans,vector<vector<int>> &temp){

        if(ans.size()==nums.size()){
            temp.push_back(ans);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(!freq[i]){
                ans.push_back(nums[i]);
                freq[i]=1;
                permutation(nums,freq,ans,temp);
                freq[i]=0;
                ans.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> temp;
        vector<int> ans;
        vector<int>freq (n,0);
        permutation(nums,freq,ans,temp);
        return temp;
    }
};