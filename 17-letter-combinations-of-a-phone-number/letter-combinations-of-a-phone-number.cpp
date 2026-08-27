class Solution {
public:

    void letters(int index,string digits,string combo[],string temp,vector<string> &ans){

        if(index==digits.size()){
            ans.push_back(temp);
            return;
        }
        int digit = digits[index]-'0';
        for(int i = 0;i<combo[digit].size();i++){
            letters(index+1,digits,combo,temp+combo[digit][i],ans);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        string combo[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        letters(0,digits,combo,"",ans);
        return ans;
    }
};