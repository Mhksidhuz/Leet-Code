class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        
        int inc = 1;
        int dec = 1;
        int n = nums.size();
        int minc = 1;
        int mdec = 1;

        for(int i=1;i<n;i++){
            
            if(nums[i-1]<nums[i]){
                minc++;
                inc = max(inc,minc);
                mdec = 1;
            }
            else if(nums[i-1]>nums[i]){
                mdec++;
                dec = max(dec,mdec);
                minc = 1;
            }
            else{
                minc = 1;
                mdec = 1;
            }
        }
        return max(inc,dec);
    }
};