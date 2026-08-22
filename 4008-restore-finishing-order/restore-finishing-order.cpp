class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {

        vector<int> ans;
        unordered_map<int, int> mpp;

        for (auto it : friends) {
            mpp[it]++;
        }

        for (int i = 0; i < order.size(); i++) {
            if(mpp.find(order[i])!=mpp.end()){
                ans.push_back(order[i]);
            }
        }
        return ans;
    }
};