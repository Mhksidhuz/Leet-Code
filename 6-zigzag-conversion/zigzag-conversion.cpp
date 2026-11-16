class Solution {
public:
    string convert(string s, int numRows) {

        if(numRows == 1 || numRows >= s.size())
            return s;
        
        vector<vector<char>> ans(numRows);
        int n = s.size();
        int index = 0;
        int direction = -1;

        for(int i=0;i<n;i++){
            
            ans[index].push_back(s[i]);

            if(index == numRows - 1)
                direction = -1;

            else if(index == 0)
                direction = 1;

            index += direction;
            
        }
        string result = "";

        for(int i = 0; i < numRows; i++) {
            for(int j = 0; j < ans[i].size(); j++) {
                result += ans[i][j];
            }
        }

        return result;
        
    }
};