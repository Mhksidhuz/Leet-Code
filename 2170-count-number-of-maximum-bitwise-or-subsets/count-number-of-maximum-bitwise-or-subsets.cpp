class Solution {
public:
    void subset(int i, vector<int>& nums, vector<int>& arr, int& maxi,
                int& count) {
        if (nums.size() == i) {
            int oru = 0;
            for (auto it : arr) {
                oru = oru | it;
            }
            if (oru > maxi) {
                maxi = oru;
                count = 1;
            } else if (oru == maxi) {
                count++;
            }
            return;
        }

        arr.push_back(nums[i]);
        subset(i + 1, nums, arr, maxi, count);
        arr.pop_back();
        subset(i + 1, nums, arr, maxi, count);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxi = 0;
        int count = 0;
        vector<int> arr;
        subset(0, nums, arr, maxi, count);
        return count;
    }
};