class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {

        string ans = "";
        
        for(int i=0;i<words.size();i++){
            string s1 = words[i];

            int j = 0;
            int total = 0;
            while(j<s1.size()){
                total += weights[s1[j]-'a'];
                j++;
            }
            char ch = 'z' - (total % 26);
            ans += ch;
        }
        return ans;
    }
};