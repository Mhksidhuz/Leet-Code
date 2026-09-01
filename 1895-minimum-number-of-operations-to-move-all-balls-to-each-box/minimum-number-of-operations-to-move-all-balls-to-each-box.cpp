class Solution {
public:
    vector<int> minOperations(string boxes) {
        int sum = 0, one = 0;
        int n = boxes.size();
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            sum += one;
            if (boxes[i] == '1')
                one++;
            ans.push_back(sum);
        }

        sum = 0, one = 0;
        for (int i = n - 1; i >= 0; i--) {
            sum += one;
            if (boxes[i] == '1')
                one++;
            ans[i] += sum;
        }

        return ans;
    }
}
;