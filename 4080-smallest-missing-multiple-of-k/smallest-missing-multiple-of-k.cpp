class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        
       int exist[101];

       for(auto it : nums){
        exist[it]=1;
       }

        int i = k;
       while(i<101){
        if(!exist[i]){
            return i;
        }
        i+=k;
       }
       return i;
    }
};