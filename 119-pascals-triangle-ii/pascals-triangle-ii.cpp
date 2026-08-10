class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>temp;
        long long ans = 1;
        temp.push_back(ans);

        for(int i=1;i<=rowIndex;i++){
            ans *= rowIndex - (i-1);
            ans /= i;
            temp.push_back(ans);
        }
        return temp;
    }
};