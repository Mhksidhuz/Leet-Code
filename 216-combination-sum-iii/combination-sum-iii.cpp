class Solution {
public:

    void print(int last,int sum,int k,vector<int> &ans,vector<vector<int>> &temp){
        if(sum==0 && ans.size()==k){
            temp.push_back(ans);
            return;
        }
        if(sum<0 || ans.size()>k) return;

        for(int i=last;i<=9;i++){
            if(i>sum) break;
            ans.push_back(i);
            print(i+1,sum-i,k,ans,temp);
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> temp;
        vector<int>ans;
        print(1,n,k,ans,temp);
        return temp;
    }
};