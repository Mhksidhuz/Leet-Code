class Solution {
public:

    void generate(string curr,int n,int open,int close,vector<string> &ans){
        if(curr.size()==2*n){
            ans.push_back(curr);
            return;
        }

        if(open<n) generate(curr+'(',n,open+1,close,ans);
        if(close<open) generate(curr+')',n,open,close+1,ans);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate("",n,0,0,ans);
        return ans;
    }
};