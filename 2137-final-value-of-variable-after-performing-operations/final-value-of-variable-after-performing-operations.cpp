class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        
        int ans = 0;

        for(auto it : operations){

            ans+= 44 - it[1];
        }
        return ans;
    }
};