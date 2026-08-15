class Solution {
public:

    void combSum(int i,vector<int>& arr, int target,vector<int>&ans,vector<vector<int>> &temp){

        if(i>=arr.size()){
            if(target==0){
                temp.push_back(ans);
            }
            return;
        }

        if(arr[i]<=target){
            ans.push_back(arr[i]);
            combSum(i,arr,target-arr[i],ans,temp);
            ans.pop_back();
        }

        combSum(i+1,arr,target,ans,temp);

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> temp;
        vector<int>ans;

        combSum(0,candidates,target,ans,temp);

        return temp;
    }
};