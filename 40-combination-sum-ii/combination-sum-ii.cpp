class Solution {
public:
    //github
    void combSum(int index,int target,vector<int>& arr,vector<int> &ans,vector<vector<int>> &temp){

        if(target==0){
            temp.push_back(ans);
            return;
        }

        for(int i=index;i<arr.size();i++){
            if(i>index && arr[i]==arr[i-1]) continue;
            if(arr[i]>target) break;
            ans.push_back(arr[i]);
            combSum(i+1,target-arr[i],arr,ans,temp);
            ans.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>ans;
        vector<vector<int>>temp;

        combSum(0,target,candidates,ans,temp);
        return temp;
    }
};