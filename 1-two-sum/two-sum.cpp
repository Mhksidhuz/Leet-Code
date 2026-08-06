class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mpp;

        for(int i=0;i<nums.size();i++){
            int value = nums[i];
            int rem = target-value;

            if(mpp.find(rem)!=mpp.end()){
                return{mpp[rem],i};
            }
            mpp[value]=i;
        }
        return{};
    }
};
//Mehak Sidhu