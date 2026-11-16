class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {

        int n = nums.size();
        int m[101] = {0};
        vector<int> ans;

        for (int i : nums) {
            m[i]++;
            if (m[i] == 2)
                ans.push_back(i);
        }

        return ans;
    }
};