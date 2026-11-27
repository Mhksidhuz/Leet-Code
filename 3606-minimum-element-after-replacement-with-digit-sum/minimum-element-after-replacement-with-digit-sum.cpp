class Solution {
public:

    int convert(int num){

        int ans = 0;

        while(num!=0){
            int digit = num%10;
            ans+=digit;
            num = num/10;
        }
        return ans;
    }

    int minElement(vector<int>& nums) {
        
        int n = nums.size();
        int mini = INT_MAX;

        for(int i=0;i<n;i++){

            nums[i] = convert(nums[i]);
            mini = min(mini,nums[i]);
        }
        return mini;
    }
};