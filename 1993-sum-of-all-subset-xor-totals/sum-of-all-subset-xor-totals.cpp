class Solution {
public:
    void subSet(int index,vector<int>&nums,int &ans,int xorr){
        if(index==nums.size()){
            ans += xorr;
            return;
        }

        xorr ^= nums[index];
        subSet(index+1,nums,ans,xorr);
        xorr = xorr ^ nums[index];

        subSet(index+1,nums,ans,xorr);
    }

    int subsetXORSum(vector<int>& nums) {
        
        int ans = 0;
        subSet(0,nums,ans,0);
        return ans;
    }
};