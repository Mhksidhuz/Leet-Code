class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
         int n = arr.size();

        long long odd = 0;
        long long even = 1;

        long long sum = 0;
        long long ans = 0;

        int MOD = 1e9 + 7;

        for(int i = 0; i < n; i++) {

            sum += arr[i];

            if(sum % 2 != 0) {
                ans += even;
                odd++;
            }
            else {
                ans += odd;
                even++;
            }

            ans %= MOD;
        }

        return ans;       
    }
};