class Solution {
public:
    int maxDistinct(string s) {
        
        unordered_map<char,int>mpp;

        for(auto it : s){
            mpp[it]++;
        }
        return mpp.size();
    }
};